; 1) Definition d'etiquette              -> 1
; 2) Nom de l'instruction                -> 11
; 3) Operandes des instrutions           -> 17
; 4) Commentaires et C++ en fin de ligne -> 35
;
;
;         2     3                 4
;         |     |                 |
;============================================================================

          .MODEL small            ;
          .STACK 512              ; Taille de la pile

;============================================================================
                                 
          .DATA                   ; DB pour Define Byte (8 bits)
                                  ; DW pour Define Word (16 bits)
          ;-------------------------------------------------------------------
          ; Declaration des variable
          ;-------------------------------------------------------------------
          message   DB   "Premier nombre?$" ; int num1 = 0;
          message2  DB   "Deuxieme nombre?$"; int num2 = 0;
          buffer    DB   2
                    DB   ?             
          buffer2    DB   2
                    DB   ?
             
	                    

     

;============================================================================

          .CODE
                                
main: 
          MOV  AX, @DATA
          MOV  DS, AX   
        
          ;-------------------------------------------------------------------
          ; Debut de votre code
          ;-------------------------------------------------------------------
                    
     do1:               ;do {
	      MOV AH, 09h
          LEA DX, message    ;cout << "Premier nombre? " << endl;
          INT 21h  
          
                         
         MOV  AH,  0Ah          
	     LEA  DX,  buffer    ;cin        
	     INT  21h         
	                       
	     ; convert ascii to number
	     SUB  buffer,   30h
	                       
	                       
	     MOV  CH,  buffer  ; >> num1;
	     
	     
	
	     CMP  CH,  64h ; && num1 < 101));
	     JGE  do1
	     CMP  CH,  0   ;} while (!(num1 > 0 
	     JLE  do1  
	               
     do2:          
          MOV AH, 09h
          LEA DX, message2    ;cout << "Deuxieme nombre? " << endl;
          INT 21h  
          
                         
         MOV  AH, 0Ah          
	     LEA  DX,  buffer2    ;cin        
	     INT  21h     
	                            
	     SUB  buffer2,   30h
	                            
	     MOV  BH,  buffer2   ; >> num2;
	     
	     CMP  BH,  64h ; && num1 < 101));
	     JGE  do2
	     CMP  BH,  0   ;} while (!(num1 > 0 
	     JLE  do2  
                       
          ;MOV  AX,  CH   
          ;MOV  BX,  BH   
          MUL  BH, CH            ; int mul = num 1 * num 2    
          
          ;transformer BX en string ascii     
          
          MOV  AL,  BL
          ADD  AL,  30h 
          MOV  CX,  9
     digit_to_ascii:
        
          
          
          
          MOV AH, 09h
          LEA DX, BX
          INT 21h
          
               
	             
	               ;cout << num1 << " x " << num2 << " = " << num1 * num2;
                   ;return 0;

           
          ;-------------------------------------------------------------------
          ; Fin de votre code
          ;-------------------------------------------------------------------

eop:      MOV    AX, 4C00h
          INT    21h

          END    main

;============================================================================