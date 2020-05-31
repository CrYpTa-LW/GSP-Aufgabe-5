	AREA |.text|, CODE, READONLY, ALIGN = 3

	EXPORT fiboai [CODE]

fiboai      PROC
			push {r4-r9} ;Variablenregister retten
			
			mov r5, r0		;arg
			mov r6, #0		;i
			mov r7, #0		;lasti1
			mov r8, #0		;lasti2
			mov r9, #0		;result

while		cmp r5, r6		;i<=arg
			blt end_while 	;Schleife ende
			
			cmp r6, #0		;i==0
			beq ieq0		;equal
			bne ine0		;not equal

ieq0		mov r9, #1		;result = 1
			mov r7, r9		;lasti1 = result
			add r6, #1		;i++
			b while
			
ine0		cmp r6, #1		;i==1
			beq ieq1		;eqaul
			bne ine1		;not equal
			
ieq1		mov r9, #1		;result = 1
			mov r8, r7		;lasti2 = lasti1
			add r6, #1		;i++
			b while
			
ine1		add r9, r7, r8  ;result = lasti1 + lasti2
			mov r8, r7		;lasti2 = lasti1
			mov r7, r9		;lasti1 = result
			add r6, #1		;i++
			b while

end_while
			mov r0, r9		;Ergebnis in r0
			
			pop {r4-r9} ;Variablenregister restaurieren
			bx lr
			ENDP
			END
		