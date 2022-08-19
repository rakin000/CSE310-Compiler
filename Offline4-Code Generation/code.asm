.MODEL SMALL
.STACK 400H
.DATA
NUM_STR DB '000000$'
.CODE
CALL main
main PROC
	MOV AX, @DATA
	MOV DS, AX; Line 1: load data to DS
	MOV BP, SP; Line 1: save SP
	ADD SP, -16
	MOV CX, 1
	PUSH CX
	POP AX
	MOV [BP+-2], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-2]
	CALL PRINT
	MOV CX, 5
	PUSH CX
	MOV CX, 8
	PUSH CX
	POP AX
	POP BX
	ADD BX, AX
	PUSH BX
	POP AX
	MOV [BP+-4], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-4]
	CALL PRINT
	MOV CX,[BP+-2]
	PUSH CX
	MOV CX, 2
	PUSH CX
	MOV CX,[BP+-4]
	POP AX
	MUL CX
	PUSH AX
	POP AX
	POP BX
	ADD BX, AX
	PUSH BX
	POP AX
	MOV [BP+-6], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-6]
	CALL PRINT
	MOV CX,[BP+-6]
	PUSH CX
	MOV CX, 9
	POP AX
	MOV DX, 0; Line 12: to avoid overflow error
	DIV CX
	PUSH DX
	POP AX
	MOV [BP+-10], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-10]
	CALL PRINT
	MOV CX,[BP+-10]
	PUSH CX
	MOV CX,[BP+-8]
	PUSH CX
	POP BX
	POP AX
	CMP AX,BX
	JLE L0
	PUSH 0
	JMP L1
	L0:
	PUSH 1
	L1:
	POP AX
	MOV [BP+-12], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-12]
	CALL PRINT
	MOV CX,[BP+-2]
	PUSH CX
	MOV CX,[BP+-4]
	PUSH CX
	POP BX
	POP AX
	CMP AX,BX
	JNE L2
	PUSH 0
	JMP L3
	L2:
	PUSH 1
	L3:
	POP AX
	MOV [BP+-14], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-14]
	CALL PRINT
	MOV CX,[BP+-12]
	PUSH CX
	MOV CX,[BP+-14]
	PUSH CX
	POP BX
	POP AX
	CMP AX, 0
	JNE L4
	CMP BX, 0
	JNE L4
	PUSH 0
	JMP L5
	L4:
	PUSH 1
	L5:
	POP AX
	MOV [BP+-16], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-16]
	CALL PRINT
	MOV CX,[BP+-12]
	PUSH CX
	MOV CX,[BP+-14]
	PUSH CX
	POP BX
	POP AX
	CMP AX, 0
	JE L6
	CMP BX, 0
	JE L6
	PUSH 1
	JMP L7
	L6:
	PUSH 0
	L7:
	POP AX
	MOV [BP+-16], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-16]
	CALL PRINT
	MOV CX,[BP+-16]
	MOV tmp0, -16
	PUSH CX
	POP AX
	MOV SI, tmp0
	INC [BP+SI]
	MOV AX, [BP+-16]
	CALL PRINT
	MOV CX,[BP+-16]
	NEG CX
	PUSH CX
	POP AX
	MOV [BP+-6], AX
	PUSH AX
	POP AX
	MOV AX, [BP+-6]
	CALL PRINT
	MOV CX, 0
	PUSH CX
	MOV AH, 4CH
	INT 21H
main ENDP
PRINT PROC
	MOV BX, 8000H
	AND BX, AX
	CMP BX, 0
	JZ NOT_NEG

	MOV BX, AX
	MOV DL, 2DH
	MOV AH, 2
	INT 21H
	MOV AX, BX
	NEG AX

	NOT_NEG:
	LEA SI, NUM_STR
	ADD SI, 6
	
	PRINT_LOOP:
	DEC SI
	MOV DX, 0
	MOV CX, 10
	DIV CX
	ADD DL, '0'
	MOV [SI], DL

	CMP AX, 0
	JNE PRINT_LOOP
	MOV DX, SI 
	MOV AH, 9
	INT 21H

	MOV DL, 0AH
	MOV AH, 2
	INT 21H
	MOV DL, 0DH
	INT 21H
	RET
PRINT ENDP
