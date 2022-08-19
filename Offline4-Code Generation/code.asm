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
	ADD SP, -10
	MOV CX, 1
	PUSH CX
	MOV CX, 2
	PUSH CX
	MOV CX, 3
	PUSH CX
	POP AX
	POP BX
	ADD BX, AX
	PUSH BX
	POP CX
	POP AX
	MUL CX
	PUSH AX
	MOV CX, 3
	POP AX
	DIV CX
	PUSH DX
	POP AX
	MOV [BP+-2], AX
	PUSH AX
	POP AX
	MOV CX, 1
	PUSH CX
	MOV CX, 5
	PUSH CX
	POP BX
	POP AX
	CMP AX,BX
	JL L0
	PUSH 0
	JMP L1
	L0:
	PUSH 1
	L1:
	POP AX
	MOV [BP+-4], AX
	PUSH AX
	POP AX
	MOV CX, 0
	PUSH CX
	POP SI
	SHL SI, 1
	NEG SI
	ADD SI, -6
	PUSH SI; Line 5: saving the address SI
	MOV CX, 2
	PUSH CX
	POP AX
	POP SI; Line 5: retrieving the address SI
	MOV [BP+SI], AX
	PUSH AX
	POP AX
	MOV CX,[BP+-2]
	PUSH CX
	MOV CX,[BP+-4]
	NOT CX
	AND CX, 1
	PUSH CX
	POP BX
	POP AX
	CMP AX, 0
	JE L2
	CMP BX, 0
	JE L2
	PUSH 1
	JMP L3
	L2:
	PUSH 0
	L3:
	POP AX
	CMP AX,0
	JE L4
	MOV CX, 0
	PUSH CX
	POP SI
	SHL SI, 1
	NEG SI
	ADD SI, -6
	PUSH CX
	POP AX
	JMP L5
	L4:
	MOV CX, 1
	PUSH CX
	POP SI
	SHL SI, 1
	NEG SI
	ADD SI, -6
	PUSH SI; Line 9: saving the address SI
	MOV CX, 0
	PUSH CX
	POP SI
	SHL SI, 1
	NEG SI
	ADD SI, -6
	MOV CX,[BP+SI]
	PUSH CX
	POP AX
	POP SI; Line 9: retrieving the address SI
	MOV [BP+SI], AX
	PUSH AX
	POP AX
	L5:
	MOV AX, [BP+-2]
	CALL PRINT
	MOV AX, [BP+-4]
	CALL PRINT
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