.586							; система команд (процессор Pentium)
.model flat, stdcall			; модель памяти, соглашение о вызовах
includelib kernel32.lib
includelib libucrt.lib
includelib "..\YSA-2024\Debug\StaticLib.lib"

ExitProcess PROTO : dword		; прототип функции для завершения процесса Windows

EXTRN lenght: proc
EXTRN write_short : proc
EXTRN write_str : proc
EXTRN copy: proc
EXTRN getLocalTimeAndDate : proc
EXTRN random: proc

.stack 4096

.const							; сегмент констант - литералы
nulError byte 'error divided by zero', 0
nul sword 0, 0

	L0 byte "Hello, test!", 0
	L1 byte "Hello", 0
	L2 sword -5
	L3 sword 7
	L4 sword 6
	L5 sword 3
	L6 sword 4
	L7 sword 2
	L8 sword 0
	L9 sword 5
	L10 sword 21
	L11 byte "Текст строки, тест", 0
	L12 sword 1
	L13 sword 100
	L14 sword 15
	L15 sword 10
	L16 byte "How are you", 0
	L17 byte "Шестнадцатиричное число A в 10й сс:", 0
	L18 sword 8
	L19 byte "Двоичное число 1000 в 10й с/с:", 0

.data							; сегмент данных - переменные и параметры
	sumRes_sum sword 0
	hi_printHello dword ?
	lenOne_differenceInLength sword 0
	lenTwo_differenceInLength sword 0
	res_differenceInLength sword 0
	hello_differenceInLength dword ?
	a_main sword 0
	q_main sword 0
	numberPrimary_main sword 0
	strB_main dword ?
	b_main sword 0
	strBCopy_main dword ?
	rand_main sword 0
	date_main dword ?
	i_main sword 0
	h_main dword ?
	c_main sword 0
	sumABC_main sword 0
	firstStroke_main dword ?
	secondStroke_main dword ?
	difBetween_main sword 0
	hexNum_main sword 0
	binNum_main sword 0

.code							; сегмент кода
;----------- sum ------------
sum PROC,	first_sum : sword, second_sum : sword, third_sum : sword  
; --- сохранить регистры ---
push ebx
push edx
; ----------------------
push first_sum
push second_sum
pop bx
pop ax
add ax, bx
push ax
push third_sum
pop bx
pop ax
add ax, bx
push ax
pop sumRes_sum

; --- восстановить регистры ---
pop edx
pop ebx
; -------------------------
mov eax, dword ptr sumRes_sum
ret
sum ENDP
;------------------------------


;----------- printHello ------------
printHello PROC 	
; --- сохранить регистры ---
push ebx
push edx
; ----------------------

push offset L0
call write_str

mov hi_printHello, offset L1
; --- восстановить регистры ---
pop eax
pop edx
pop ebx
; -------------------------
mov eax, dword ptr hi_printHello
ret
printHello ENDP
;------------------------------


;----------- differenceInLength ------------
differenceInLength PROC,	strokeOne_differenceInLength : word, strokeTwo_differenceInLength : word  
; --- сохранить регистры ---
push ebx
push edx
; ----------------------
mov eax, dword ptr strokeOne_differenceInLength
push eax
call lenght
push eax
pop lenOne_differenceInLength

mov eax, dword ptr strokeTwo_differenceInLength
push eax
call lenght
push eax
pop lenTwo_differenceInLength

push lenOne_differenceInLength
push lenTwo_differenceInLength
pop bx
pop ax
sub ax, bx
push ax
pop res_differenceInLength

call printHello
mov hello_differenceInLength, eax
; --- восстановить регистры ---
pop edx
pop ebx
; -------------------------
mov eax, dword ptr res_differenceInLength
ret
differenceInLength ENDP
;------------------------------


;----------- MAIN ------------
main PROC

push L2
pop a_main

push a_main
push L3
pop bx
pop ax
add ax, bx
push ax
push L4
pop bx
pop ax
imul ax, bx
push ax
push L5
pop bx
pop ax
cmp nul, bx
je errorExit 
cdq
idiv bx
push ax
push L6
pop bx
pop ax
sub ax, bx
push ax
push L7
pop bx
pop ax
cdq
idiv bx
push dx
pop a_main

push a_main
call write_short

push L8
pop q_main

push L9
push L9
push L9
pop bx
pop ax
imul ax, bx
push ax
push L9
push L9
pop bx
pop ax
imul ax, bx
push ax
push L9
pop bx
pop ax
add ax, bx
push ax
push L9
pop bx
pop ax
imul ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax
pop q_main

push L10
pop numberPrimary_main

push numberPrimary_main
call write_short

mov strB_main, offset L11
push L12
mov eax, dword ptr strB_main
push eax
call lenght
push eax
pop bx
pop ax
add ax, bx
push ax
pop b_main

push b_main
call write_short

mov eax, dword ptr L9
push eax
mov eax, dword ptr strB_main
push eax
mov eax, dword ptr strBCopy_main
push eax
call copy
mov strBCopy_main, eax
push strBCopy_main
call write_str

mov eax, dword ptr L13
push eax
mov eax, dword ptr L8
push eax
call random
push eax
pop rand_main

push rand_main
call write_short

call getLocalTimeAndDate
mov date_main, eax
push date_main
call write_str

push L8
pop i_main

cyclenext0:
mov dx, i_main
cmp dx, L14
jg cycle0
push i_main
call write_short

push i_main
push L12
pop bx
pop ax
add ax, bx
push ax
pop i_main

jmp cyclenext0
cycle0:

call printHello
mov h_main, eax
push L9
pop a_main

push L15
pop b_main

push L8
pop c_main

mov eax, dword ptr c_main
push eax
mov eax, dword ptr b_main
push eax
mov eax, dword ptr a_main
push eax
call sum
push eax
pop sumABC_main

push sumABC_main
call write_short

mov firstStroke_main, offset L1
mov secondStroke_main, offset L16
mov eax, dword ptr secondStroke_main
push eax
mov eax, dword ptr firstStroke_main
push eax
call differenceInLength
push eax
pop difBetween_main

push difBetween_main
call write_short

push L15
pop hexNum_main


push offset L17
call write_str

push hexNum_main
call write_short

push L18
pop binNum_main


push offset L19
call write_str

push binNum_main
call write_short

jmp goodExit
errorExit:
push offset nulError
call write_str
goodExit:
push 0
call ExitProcess
main ENDP
end main