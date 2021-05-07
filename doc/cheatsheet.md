## Registres Generaux

Le  prefix R correspond a la version 64 bits du registre.  
Le prefix E correspond a la version 32 bits du registre.   
Pour les registres A, B, C, D, il est possible d'acceder a l'octet fort/faible avec respectivement le suffix H/L.    
Exemple: AH permet d'acceder a l'octet fort du registre A.  
• (R,E)AX - [AH:AL] : accumulateur, stockage du retour d’une fonction ou d’un appel systeme.  
• (R,E)BX - [BH:BL] : decalage dans le segment des donnees pointe par le registre DS.    
• (R,E)CX - [CH:CL] : compteur de boucle (instruction loop).  
• (R,E)DX - [DH:DL] : registre de donnees, utilise lors des operations d’entrees/sorties et pour certains calculs longs (instructions div et mul).  
• (R,E)SI : Source Index : pointeur ”source” pour les operations sur des chaines de caracteres.  
• (R,E)DI : Destination Index : pointeur ”destination” pour les operations sur des chaines de caracteres.  
• (R,E)BP : Base Pointer : Pointeur du debut de la pile memoire du programme.  
• (R,E)SP : Stack Pointer : Pointeur de la position actuelle de la pile.  

## Registres de controle  

• (E)IP : Instruction Pointer : Registre stockant l’adresse de la prochaine instruction a ex ` ecuter ´
(relatif au segment de code).  
• (E)FLAGS : registre contenant des valeurs binaires (flag) utilisees dans certaines instructions  
## Liens
- https://www.fil.univ-lille1.fr/~meftali/PdM/Theme1.pdf   
- https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/   
- https://faydoc.tripod.com/cpu/jl.htm  
- http://osr600doc.xinuos.com/en/SDK_sysprog/SCL_SysCallErrHdl.html   
- https://aaronbloomfield.github.io/pdr/book/x86-64bit-ccc-chapter.pdf  
- https://www.tutorialspoint.com/what-are-the-calling-conventions-for-unix-and-linux-system-calls-on-i386-and-x86-64  
- https://asmtutor.com/  
