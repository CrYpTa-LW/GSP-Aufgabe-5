	AREA |.text|, CODE, READONLY, ALIGN = 3

	EXPORT fiboar [CODE]

fiboar      PROC
			push {r4-r9,lr} ;Variablenregister retten

			mov r5, r0		;arg
			
			cmp r5, #0    	;arg == 0
			beq	argEq0		;equal 
			bne argNe0		;not equal

argEq0		mov r0, #1		;result = 1
			b end_proc		;return

argNe0		cmp r5, #1		;arg == 1
			beq	argEq1		;equal
			bne argNe1		;not equal
			
argEq1		mov r0, #1		;result 1
			b end_proc		;return

argNe1		sub r0, r5, #1	;arg-1
			bl  fiboar		;fiboar(i-1)
			mov	r6, r0		;r6 = fiboar(i-1)
			sub r0, r5, #2  ;arg-2
			bl fiboar		;fiboar(i-2)
			mov	r7, r0		;r7 = fiboar(i-2)
			add r0, r6, r7	;r0 = fiboar(i-1) + fiboar(i-2)
			b end_proc

end_proc
			pop {r4-r9,lr} ;Variablenregister restaurieren
			bx lr
			ENDP
			END