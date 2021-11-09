#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool isValidInteger(char* substr){ // control whether a token is an integer or not

    if(strlen(substr)>100){  // control the limit of integer size

    printf("Error:Integer number is too large!\n");
  

        return (false);

        }

    if((substr[0]=='+') || (substr[0]=='-' && (substr[1]== ' ' || substr[1]=='-'||substr[1]=='0')) || (substr[0]=='0' && strlen(substr)>1) ){ 
    //control invalid integers such as +5, - 12 
       // printf("Error:Integer includes unrecognized character integer is not valid! %s \n", substr);
       
        return (false);

        }

    int i=0;
    if(substr[0]!='-'){ //control invalid integer tokens
    
        for(i;i<strlen(substr);i++){  

        if (substr[i] != '0' && substr[i] != '1' && substr[i] != '2'

        && substr[i] != '3' && substr[i] != '4' && substr[i] != '5'

        && substr[i] != '6' && substr[i] != '7' && substr[i] != '8'

        && substr[i] != '9' ){

            //printf("Error:Integer includes unrecognized character integer is not valid!\n");
           
            return (false);
           }    
        }
}
 if(substr[0]=='-'){ //control negative integer tokens
    
    int i=1;
    for(i;i<strlen(substr);i++){  

        if (substr[i] != '1' && substr[i] != '2'

        && substr[i] != '3' && substr[i] != '4' && substr[i] != '5'

        && substr[i] != '6' && substr[i] != '7' && substr[i] != '8'

        && substr[i] != '9' ){

            //printf("Error:Integer includes unrecognized character integer is not valid! %s \n",substr);
            
            return (false);
           }
    
}

}
    //printf("IntConstant %s \n", substr);
   
    return (true);

}

bool isVariable(char* substr){  //control whether a token is an identifier or not
   
    
    if(strlen(substr)>20){ // control the limit of identifier size

        printf("Error:Identifier  is too large!  \n");
       
        return (false);

    }
         // control invalid identifiers and unrecognized characters
    if(substr[0]!='_'&& substr[0]!='a' && substr[0]!='b'&& substr[0]!='c'&&substr[0]!='d'&& substr[0]!='e'&&
     substr[0]!='f'&& substr[0]!='g'&& substr[0]!='h'&& substr[0]!='i'&& substr[0]!='j'&& substr[0]!='k'&& substr[0]!='l'&& 
     substr[0]!='m'&& substr[0]!='n'&& substr[0]!='o'&& substr[0]!='p'&& substr[0]!='q'&& substr[0]!='r'&& substr[0]!='s'&& 
     substr[0]!='t'&& substr[0]!='u'&& substr[0]!='v'&& substr[0]!='w'&& substr[0]!='x'&& substr[0]!='y'&& substr[0]!='z'&& 
     substr[0]!='A'&& substr[0]!='B'&& substr[0]!='C'&& substr[0]!='D'&& substr[0]!='E'&& substr[0]!='F'&& substr[0]!='G'&&
     substr[0]!='H'&& substr[0]!='I'&& substr[0]!='J'&& substr[0]!='K'&& substr[0]!='L'&& substr[0]!='M'&& substr[0]!='N'&& 
     substr[0]!='O'&& substr[0]!='P'&& substr[0]!='Q'&& substr[0]!='R'&& substr[0]!='S'&& substr[0]!='T'&& substr[0]!='U'&&
     substr[0]!='V'&& substr[0]!='W'&& substr[0]!='X'&& substr[0]!='Y'&& substr[0]!='Z'){
    
        //printf("IS NOT VALID IDENTIFIER \n");
        
        return(false);
        
    }
    
    int x=1;
    for(x; x<strlen(substr)-1;x++){   
        
        char ch;
        ch=substr[x];
        
        // control invalid identifiers and unrecognized characters
        if (ch == ' ' || ch == '+'|| ch == '~' || ch == '&'|| 
        ch == '$' || ch == '#' || ch == '%' || ch == '?' || 
        ch == '@' || ch == '-' || ch == '*' || ch == '/' || 
        ch == ',' || ch == ';' || ch == '>' || 
        ch == '<' || ch == '=' || ch == '(' || ch == ')' || 
        ch == '[' || ch == ']' || ch == '{' || ch == '}'){
        
        //printf("IS NOT VALID IDENTIFIER \n");
        
        return (false);
        }
        
    }
        return (true);
}

bool isIntegerVariable(char* str,char *variableList,int vIndex) {
    int i=0;
    for ( i ; i < vIndex; i++) {
        if (!strcmp(str, variableList[i])) {
            return true;
        }
    }

    return false;
}

bool isKeyword(char* substr){ //control whether a token is a keyword or not

    char keywords[10][20]= {  // arrays of accepted keywords 
    {'i','n','t','\0'},
    {'m','o','v','e','\0'},
    {'t','o','\0'},
    {'l','o','o','p','\0'},
    {'o','u','t','\0'},
    {'f','r','o','m','\0'},
    {'t','i','m','e','s','\0'},
    {'n','e','w','l','i','n','e','\0'},
    {'a','d','d','\0'},
    {'s','u','b','\0'}
    };
    
    
   int j=0;
   
   for(j; j<10;j++){  // control the substring is a keyword or not
        
        if(strcmp(keywords[j],substr)==0){
           
            return(true);
        }
    }
  
  
  
    return(false);
    
}

void find_declaredVar(char* substr, char declaredVar[20][20], int dIndex, int lineCount ) { //To find wheter a varable is declared or not before used.

   int i=0;
   int declared=0;


    for (i ; i <dIndex ; i++) {
        if(!strcmp(declaredVar[i], substr)){
           //printf("'%s' is a variable.\n", substr);
           declared++;
           break;
           
        }

    }
        if(declared==0){
        printf("Error in line '%d': Variable '%s' is not declared before used! \n ",lineCount,substr);
        exit(0);
 
   
}
}


//Parse function controls the program line by line and finds the errors.
int parse(char line[20][20],int wordCount,int lineCount, int dIndex, char declaredVar[20][20],int integerList[1000],int iIndex,int iteration,int loopActive) { //declared variable, variable stringlerini tutan bir liste olacak 


        int declaredFalse = 0;

            if (wordCount == 0) { return 0; }
    

            //Int
            if (!strcmp(line[0], "int")) {
                //printf("'int' is a keyword.\n");
    

                //Variable
                if (line[1] == NULL) {
                    printf( "Error in line '%d': Variable is expected in line ",lineCount);
                    //printf( " '%d' .\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[1])) {
                    printf(" Error in line '%d': '%s' is a keyword. Variable is expected .\n",lineCount, line[1]);
                    exit(0);
                }
                else if (isVariable(line[1])) {
                    //printf("'%s' is a variable.\n", line[1]);
    
                }
                else {
                    printf("Error in line '%d': '%s' is not a variable. Variable is expected.\n",lineCount, line[1]);
                   exit(0);
                }
    

                //End Of Line
                if (wordCount == 2) {
                   // printf("'.' End of Line.\n");
                }
                else {
                    printf("Error in line '%d': End of line is expected.\n",lineCount);
                   exit(0);
                }
            }
    

    

            //Move (For assignment)
            else if (!strcmp(line[0], "move")) {
                //printf("'move' is a keyword.\n");               
    

                //Integer Or Variable
                int moveInt = 0;
                if (line[1] == NULL) {
                    printf("Error in line '%d':Integer or variable are expected.\n",lineCount);
                   exit(0);
                }
                else if (isKeyword(line[1])) {
                    printf("Error in line '%d':'%s' is a keyword. Integer or variable are expected.\n",lineCount , line[1]);
                   exit(0);
                }
                else if (isValidInteger(line[1])) {
                    //printf("'%s' is an integer.\n", line[1]);
    
                    moveInt = atoi(line[1]); //atoi function converts string to int
                }
                else if (isVariable(line[1])) {
                    
                    find_declaredVar(line[1],declaredVar, dIndex,lineCount);
                    
                    int i = 0;
                    for ( i;i < dIndex; i++) { //If the variable is declared its value is held in moveInt.
                        if (!strcmp(declaredVar[i], line[1])) {
                            moveInt = integerList[i]; 
                            break;
                        }
                    }
                }
                else {
                    printf("Error in line '%d':'%s' is not a integer or variable. Integer or variable are expected.\n",lineCount, line[1]);
                   exit(0);
                }
    

                //To
                if (line[2] == NULL) {
                    printf("Error in line '%d':Keyword 'to' is expected.\n",lineCount);
                    exit(0);
                }
                else if (!strcmp(line[2], "to")) {
                    //printf("'to' is a keyword.\n");
                }
                else {
                    printf("Error in line '%d':Keyword 'to' is expected.\n",lineCount);
                    exit(0);
                }
    

                //Variable
                if (line[3] == NULL) {
                    printf("Error in line '%d':Variable is expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[3])) {
                    printf("Error in line '%d':'%s' is a keyword. Variable is expected.\n",lineCount, line[3]);
                    exit(0);
                }
                else if (isVariable(line[3])) {
                    find_declaredVar(line[3],declaredVar, dIndex,lineCount);
    
                    int index = 0;
                    for ( index; index < dIndex; index++) { //If the variable is declared moveInt is given as the value.
                        if (!strcmp(declaredVar[index], line[3])) {
                            integerList[index] = moveInt;
                            break;
                        }
                    }
                }
                else {
                    printf("Error in line '%d':'%s' is not a variable. Variable is expected.\n",lineCount, line[3]);
                    exit(0);
                }
    
                //End Of Line
                if (wordCount == 4) {
                    //printf("'.' End of Line.\n");
                }
                else {
                    printf("Error in line '%d':End of line is expected.\n",lineCount);
                    exit(0);
                }
            }
    

            //Add
            else if (!strcmp(line[0], "add")) {
                //printf("'add' is a keyword.\n");
    

                //Integer Or Variable
                int addInt = 0;
                if (line[1] == NULL) {
                    printf("Error in line '%d':Integer or variable are expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[1])) {
                    printf("Error in line '%d':'%s' is a keyword. Integer or variable are expected.\n",lineCount, line[1]);
                    exit(0);
                }
                else if (isValidInteger(line[1])) {
                    //printf("'%s' is an integer.\n", line[1]);
                    addInt = atoi(line[1]);
                }
                
                else if (isVariable(line[1])) {
                    find_declaredVar(line[1],declaredVar, dIndex,lineCount);// to check variable is declared or not before used (function is call)


                    int i = 0;
                    for (i; i < dIndex; i++) { //defined value to the add 
                        if (!strcmp(declaredVar[i], line[1])) {
                            addInt = integerList[i];
                            break;
                        }
                    }
                       

                }
                else {
                    printf("Error in line '%d':'%s'is not a integer or variable. Integer or variable are expected.\n",lineCount, line[1]);
                   exit(0);
                }
    
                //To
                if (line[2] == NULL) {
                    printf("Error in line '%d':Keyword 'to' is expected.\n",lineCount);
                    exit(0);
                }
                else if (!strcmp(line[2], "to")) {
                    //printf("'to' is a keyword.\n");
                }
                else {
                    printf("Error in line '%d':Keyword 'to' is expected.\n",lineCount);
                   exit(0);
                }
    

                //Variable
                if (line[3] == NULL) {
                    printf("Error in line '%d':Variable is expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[3])) {
                    printf("Error in line '%d':'%s' is a keyword. Variable is expected.\n",lineCount, line[3]);
                    exit(0);
                }
                else if (isVariable(line[3])) {
                    find_declaredVar(line[3],declaredVar, dIndex,lineCount);
                    if(loopActive==1){ //If command is in loop, operate the statement iteration times. 
                    
                    int k = 0;
                    for ( k; k<dIndex; k++) {
                        
                        if (!strcmp(declaredVar[k], line[1])) {
     
                                iteration = integerList[k] ; 
                                
                                break;

                        }
                    }
                    
                  int i = 0;
                    for ( i; i<dIndex; i++) {
                        
                        if (!strcmp(declaredVar[i], line[3])) {
                            
                            for(iteration;iteration>0;iteration--){
                                integerList[i] += iteration;  
                                                            
                            }
                        break;
                        }
                    }

                    }
                    else{

                   int i = 0;
                    for ( i;i < dIndex; i++) {
                        if (!strcmp(declaredVar[i], line[3])) {
                            integerList[i] += addInt;
                            break;
                        }
                    }
                    }

                }
                else {
                    printf("Error in line '%d':'%s' is not a variable. Variable is expected.\n",lineCount, line[3]);
                   exit(0);
                }

                //End Of Line
                if (wordCount == 4) {
                    //printf("'.' End of Line.\n");
                }
                else {
                    printf("Error in line '%d':End of line is expected.\n",lineCount);
                   exit(0);
                }
            }
    

    

            //Sub
            else if (!strcmp(line[0], "sub")) {
                //printf("'sub' is a keyword.\n");
    
                //Integer Or Variable
                int subInt = 0;
                if (line[1] == NULL) {
                    printf("Error in line '%d':Integer or variable are expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[1])) {
                    printf("Error in line '%d':'%s' is a keyword. Integer or variable are expected.\n",lineCount ,line[1]);
                    exit(0);
                }
                else if (isValidInteger(line[1])) {
                    //printf("'%s' is an integer.\n", line[1]);
                    subInt = atoi(line[1]);
                }
                
                else if (isVariable(line[1])) {
                    find_declaredVar(line[1],declaredVar, dIndex,lineCount);
    
                    int i = 0;
                    for ( i;i < dIndex; i++) {
                        if (!strcmp(declaredVar[i], line[1])) {
                            subInt = integerList[i];
                            break;
                        }
                    }
                }
                else {
                    printf("Error in line '%d':'%s' is not a integer or variable. Integer or variable are expected.\n",lineCount, line[1]);
                    exit(0);
                }
    

                //To
                if (line[2] == NULL) {
                    printf("Error in line '%d':Keyword 'from' is expected.\n",lineCount);
                    exit(0);
                }
                else if (!strcmp(line[2], "from")) {
                    //printf("'to' is a keyword.\n");
                }
                else {
                    printf("Error in line '%d':Keyword 'from' is expected.\n",lineCount);
                    exit(0);
                }
    

                //Variable
                if (line[3] == NULL) {
                    printf("Error in line '%d':Variable is expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[3])) {
                    printf("Error in line '%d':'%s' is a keyword. Variable is expected.\n",lineCount, line[3]);
                    exit(0);
                }
                else if (isVariable(line[3])) {
                    find_declaredVar(line[3],declaredVar, dIndex,lineCount);
                    
                                        if(loopActive==1){ //If command is in loop, operate the statement iteration times. 
                    
                    int k = 0;
                    for ( k; k<dIndex; k++) {
                        
                        if (!strcmp(declaredVar[k], line[1])) {
     
                                iteration = integerList[k] ; 
                                
                                break;

                        }
                    }
                    
                  int i = 0;
                    for ( i; i<dIndex; i++) {
                        
                        if (!strcmp(declaredVar[i], line[3])) {
                            
                            for(iteration;iteration>0;iteration--){
                                integerList[i] -= iteration;  
                                                            
                            }
                        break;
                        }
                    }

                    }
                    else{

                   int i = 0;
                    for ( i;i < dIndex; i++) {
                        if (!strcmp(declaredVar[i], line[3])) {
                            integerList[i] -= subInt;
                            break;
                        }
                    }
                    }
    

                }
                else {
                    printf("Error in line '%d':'%s' is not a variable. Variable is expected.\n",lineCount, line[3]);
                    exit(0);
                }
    

                //End Of Line
                if (wordCount == 4) {
                    //printf("'.' End of Line.\n");
                }
                else {
                    printf("Error in line '%d':End of line is expected.\n",lineCount);
                    exit(0);
                }
            }
    

        //Out
        else if (!strcmp(line[0], "out")) {
           //printf("out parse edeiliyor.\n");
            
                if (line[1] == NULL) {
                    printf("Error in line '%d': Wrong output format. Integer, variable or string are expected.\n",lineCount);
                    exit(0);
                }
                else if ( (isValidInteger(line[1])|| strchr(line[1], '*') ||isVariable(line[1]) ||!strcmp(line[1], "newline"))) { //star is the symbol for string values.
                    int k = 0;
                    for ( k; k<dIndex; k++) {
                        
                        if (!strcmp(declaredVar[k], line[1])) {
     
                                iteration = integerList[k] ; 
                                
                                break;

                        }
                    }
                    if(isVariable(line[1])){
                        
                        int outIndex=0;
                        if(loopActive==0){
                        for(outIndex;outIndex<strlen(declaredVar);outIndex++){
                            if(!strcmp(declaredVar[outIndex], line[1])){
                                printf("'%s':",declaredVar[outIndex]);
                                printf("'%d'\n",integerList[outIndex]);
                                break;
                            }
                        }                            
                    }    
                    else{
                        int i =0;
                        //int print = iteration;

                        for(outIndex;outIndex<strlen(declaredVar);outIndex++){
                            if(!strcmp(declaredVar[outIndex], line[1])){
                                printf("'%s':\n",declaredVar[outIndex]);
                                for(iteration;iteration>0;iteration--){
                                
                                printf("'%d'\n",iteration);
                                
                            }
                            break;
                        }

                        }
                        }
                    }
                    
                    if (wordCount==2) {
                    //printf(" accepted format \n");
                    }

                    if(!strcmp(line[2], ",")){

                        int startIndex=2;
                        int odd=startIndex+1;
                        int even=startIndex;
                        for(startIndex;startIndex<wordCount-2;startIndex++){

                           if(strcmp(line[odd], "newline")&& isKeyword(line[odd])){
                                printf("Error in line '%d': List element (<int_value> || <string> || newline) is expected.\n",lineCount);
                                exit(0);

                            }
                            //Control <list_element>
                            else if(isValidInteger(line[odd])|| strchr(line[odd], '*') || isVariable(line[odd]) ||!strcmp(line[odd], "newline")){ //|| !strcmp(line[1][1], "*")
                                //true format
                                //printf("Kabul etti odd: '%d'\n",odd);

                            if(isVariable(line[odd])){//if command is in loop, operate iteration times.
                        
                                int outIndex=0;
                                if(loopActive==0){
                                    for(outIndex;outIndex<strlen(declaredVar);outIndex++){
                                        if(!strcmp(declaredVar[outIndex], line[odd])){
                                            printf("'%s':",declaredVar[outIndex]);
                                            printf("'%d'\n",integerList[outIndex]);
                                            break;
                                    }
                                }                            
                            }    
                    else{
                        int i =0;
                        //int print = iteration;

                        for(outIndex;outIndex<strlen(declaredVar);outIndex++){
                            if(!strcmp(declaredVar[outIndex], line[odd])){
                                printf("'%s':\n",declaredVar[outIndex]);
                                for(iteration;iteration>0;iteration--){
                                
                                printf("'%d'\n",iteration);
                                
                                }
                            break;
                            }

                            }
                        }

                    }                          
                                odd=odd+2;
                                
                    }
                            else{
                                printf("Error in line '%d': List element (<int_value> || <string> || newline) is expected.\n",lineCount);
                                exit(0);
                            }
                            if((!strcmp(line[even], ",")) ){
                                //true output format
                                even=even+2;
                            }

                            else{
                                printf("Error in line '%d': ',' is expected.\n",lineCount);
                                exit(0);
                            }
                        } 

                    }
                    
                    else{
                        printf("Error in line '%d': Wrong output format. ',' is expected.\n",lineCount);
                        exit(0);                    
                    }



                }
                else{
                        printf("Error in line '%d': Wrong output format. Integer, variable or string are expected.\n",lineCount);
                        exit(0);                    
                }
                


        }
    

        //Loop
            else if (!strcmp(line[0], "loop")) {
               //printf("'loop' is a keyword.\n");

               
    

            //Integer Or Variable
                int loopInt = 0;
                if (line[1] == NULL) {
                    printf("Error in line '%d':Integer or variable are expected.\n",lineCount);
                    exit(0);
                }
                else if (isKeyword(line[1])) {
                    printf("Error in line '%d': '%s' is a keyword. Integer or variable are expected.\n",lineCount, line[1]);
                    exit(0);
                }
                else if (isValidInteger(line[1])) {
                    //printf("'%s' is an integer.\n",line[1]);
    
                   loopInt = atoi(line[1]);
                }
                else if (isVariable(line[1])) {
                    
                    find_declaredVar(line[1],declaredVar, dIndex,lineCount);
    
                    int i = 0;
                    for (i; i < dIndex; i++) {
                        if (!strcmp(declaredVar[i], line[1])) {
                            loopInt = integerList[i];
                            iteration = loopInt;
                            break;
                        }
                    }
                }
                else {
                    printf("Error in line '%d': '%s' is not a integer or variable. Integer or variable are expected.\n",lineCount, line[1]);
                    exit(0);
                }
    

                //Times
                if (line[2] == NULL) {
                    printf("Error in line '%d': Keyword 'times' is expected.\n",lineCount);
                   exit(0);
                }
                else if (!strcmp(line[2], "times")) {
                    //printf("'times' is a keyword.\n");
                }
                else {
                    printf("Error in line '%d': Keyword 'times' is expected.\n",lineCount);
                    exit(0);
                }
    

                //Code
                int i = 0;
                for (i; i < loopInt; i++) {
                    char newCode[100] = "";
                    int i = 3;
                    for (i; i < wordCount; i++) {
                        strcat(newCode, " ");
                        strcat(newCode, line[i]);
                    }
                    strcat(newCode, ".");
                 
                }
    

                //End Of Line
                if (wordCount >= 3) {
                    //printf("'.' End of Line.\n");
                }
                else {
                    printf("Error in line '%d' :End of line is expected.\n",lineCount);
                    exit(0);
                }
            }
    

            else {
                printf("%s", line[0]);
            }
        
    }

    

int main(int argc, char *argv[]) {
    
    
    FILE *cFptr; // file pointer to read
    FILE *oFptr; // file pointer to write


char fnamer[100]="";		//Storing File Path/Name of Image to Display
printf("\n\nPlease Enter the Full Path of the Input file you want to view: \n");
scanf("%s",&fnamer);

if((cFptr=fopen(strcat( fnamer, ".ba"),"r"))==NULL || (oFptr=fopen("myscript.lx","w"))==NULL ){

    printf("File could not be opened!\n");
    fprintf(oFptr,"File could not be opened!\n");
}

else{
    
    char line[15][20];// 2-d char array to hold lines of tokens.
    
    int counter=0;//word count for each line
    int lineCount=1;//number of line to print error messages

    int loopActive=0;// 1 if loop exists.
    
    int iteration =0;  // number of line

    int integerList[1000] = { 0 }; int iIndex = 0; //int array to hold variable values. 

    char declaredVar[20][20]; //2-d char array to hold declared variables.
    int dIndex=0;
    
    char c; // character read from myscript.ba
    int numLine = 1; // number of line

    int charCount = 0; // holds the index value for the tempStr array
    char* tempStr = (char*)malloc (100); // tempStr is a pointer (array) that holds the token
    
    int control=0; // counter to control index while integer is - 5 etc.
   

while ((c = fgetc(cFptr)) != EOF) { // read file char by char until EOF

    char nextChar=fgetc(cFptr); // gets the next character to control conditions

      
        if (c == '\n') // control and update the line number 
        
            numLine++;

        // Exclude comment line starting with '{' and ending with '}' 
        if (c == '{') {

            while ((c = fgetc(cFptr)) != '}') {
               if(c==EOF){ // if } never met before reaching EOF an error message is printed
                printf("Error:Reached End Of File  before the end of comment line!\n "); // error message writing to screen
              
                exit(1); // program end with EOF error
               }
            }  
                numLine++; // update the line number                    
        }
        
        
       else if(nextChar=='"'){  // control string constant   ! when we use  " "   characters  C gives an error message so we used " " characters instead  for example "Sum:"
                char* stringArray = (char*)malloc (1000);

                int stringArrayCounter=0;
                stringArray[stringArrayCounter]='"';
                stringArrayCounter++;
                stringArray[stringArrayCounter]='*';
                stringArrayCounter++;

                char p='"';
                while((c = fgetc(cFptr))!='"'){  
                
                    if(c==EOF){ // if " never met before reaching EOF an error message is printed
                        printf("Error:Reached End Of File  before the end of StringConstant !\n "); // error message writing to screen
                       
                        exit(1); // program end with EOF error
                    }  

                   tempStr[charCount]=c;
                   charCount++;

                   stringArray[stringArrayCounter]=c;
                   stringArrayCounter++;
                   
                   
                }

                
    			
				stringArray[stringArrayCounter]='"';
                stringArrayCounter++;
                stringArray[stringArrayCounter]='\0';
                stringArrayCounter=0;

                tempStr[charCount]='\0'; 
                charCount=0; // update charCount
                
                
                strcpy(line[counter],stringArray);
                counter+=1;
                int cont=0;
                for(cont;cont<stringArrayCounter;cont++){
                    printf("'%s'",stringArray[stringArrayCounter]);
                }
            
                
                int k=0;
           
        }
        
        
        else if ( isalnum(c)==false &&c != ' ' && c != '+'&&  c != '-' && c != '*' && c != '\n' &&      //control unrecognized characters 
        c != ',' && c!= '[' &&  c!= ']'  && c != '{' && c!= '}' && c != '.' && c != '"' && c != '"'&& c != '_'){ 
            
            printf("Error:Unrecognized character is used!\n");        //if come across with unrecognized characters an error mesage is printed
            
            charCount = 0;
        }
        
        
        
        else if (isspace(c)) { // skip spaces
      
                charCount = 0;  // to skip spaces assign 0 to charCount
        } 
        else if(isdigit(c)||c=='-'|| c=='+'||(isdigit(c)&&(nextChar=='.'))){ // control to split integers for example - 5233  or others 

            if(control>0){ //if condition to control - 5 is true(invalid integer)
                charCount=control;
                tempStr[charCount] = c; // add character to tempStr array
                charCount++;
                control=0;

            }

            else{           
                tempStr[charCount] = c;  // add character to tempStr array
                charCount++;
            }

                
            if(c=='-' && nextChar==' '){ // check conditions for tokens such as - 5
                

                tempStr[charCount] = ' '; // add space to perform the tokenization
                charCount++;
                control=charCount;

            }

            else if(isdigit(c)&&(nextChar==' ') ){ // if end of integer  token

                tempStr[charCount] ='\0'; //initialize the end of array
                
                strcpy(line[counter],tempStr);
                counter+=1;
                
                isValidInteger(tempStr);        
                charCount=0; //make charCount 0 for new tokens to come
                 
            }
            
        }
        
      
        else{ //  other cases for token 
        
             
                    
            if(c=='.'){  // to control end of line
              
                if(isdigit(nextChar)){// check if the number is float (ex: 456.674)

                charCount=charCount;
            }
                else if(c=='.'&& nextChar==' '){// check if the number is float (ex: 456.674  or 123.)   
                    
                    tempStr[charCount]='.';
                    charCount++;
                    tempStr[charCount]='\0';// end of char
                    
                    strcpy(line[counter],tempStr);
                    counter+=1;
                    
                    printf("Error:Integer includes unrecognized character integer is not valid! %s \n", tempStr);
                
                    charCount=0;
                }

                else if(nextChar=='\n'|| nextChar==' '||nextChar=='{'|| nextChar==EOF){  //nextChar=='\0'  to control end of file 



                    if (!strcmp(line[0], "int")&&isVariable(line[1])) { // for each int variable declaration the variable is added to declaredVar array.
                        strcpy(declaredVar[dIndex] , line[1]);
                        integerList[iIndex++] = 0;
                        //printf("DeclaredVar: %s \n",declaredVar[dIndex]);                       
                        //printf("Index: %d \n",dIndex);
                        dIndex++;
                    }
                
                /*int ind=0 ; //for loop to print tokens of each line to parse.
                printf("\n");
                for (ind ; ind<counter ; ind++){
                    printf("%s ",line[ind]);
                
                }*/
                printf("\n");
               
                parse(line,counter,lineCount,dIndex, declaredVar,integerList,iIndex,iteration,loopActive);// call the parse function and parse the line.
                counter=0; 
                lineCount++;

                if(nextChar==EOF){
                    printf("Parsing is finished. Program ended successfully.");
                }
                
                //printf("EndOfLine \n");
                
                 }
                 charCount=0;
                
                
            }
            
            else if(c=='['){  // to control open  block
                //printf("OpenBlock \n");
                loopActive=1;

                charCount=0;
            }
            else if(c==']'){ // to control  close block
                //printf("CloseBlock \n");

                lineCount++;
                charCount=0;
                loopActive=0;

            
            }
            
            else if(c==','){  // to control seperator ,   
            
                strcpy(line[counter],","); // add seperator into line 
                counter+=1;
           
                charCount=0;
            }
            
            
            tempStr[charCount] = c;   // if seperator , comes  should not add to tempStr
            
            charCount+=1;
            
            if(nextChar==' '|| nextChar=='.'|| nextChar==','|| nextChar==']'|| nextChar=='\n'){  //  add nextChar==',' to control seperator 
            
              tempStr[charCount] = '\0';
            
              
                if(isKeyword(tempStr)){  // controls whether token is a keyword or not
              
                
                    
                    if(!strcmp(tempStr, "times")){
                        
                    
                        strcpy(line[counter],tempStr);
                    
                        counter+=1;      
                        
                        /*int ind=0 ; 
                        printf("\n");
                        for (ind ; ind<counter ; ind++){
                             
                           printf("%s ",line[ind]);
                        }*/
                        printf("\n");
                        parse(line,counter,lineCount,dIndex, declaredVar,integerList,iIndex,iteration,loopActive);// call the parse function and parse the line.
                        counter=0; 
                        lineCount++;
                         } 
                        
                    else{
                        strcpy(line[counter],tempStr);
                        counter+=1;
                
                    }

                    
                    //printf("Keyword %.*s \n",charCount,tempStr);
                   
                }
                else if(isVariable(tempStr)){ //controls whether token is a identifier or not
   
                        strcpy(line[counter],tempStr);
                        counter+=1;
                    
                    int i=strlen(tempStr);
                
                    
                   
                   
                    //printf("Identifier %.*s\n",charCount,tempStr);
               }
                charCount=0;
                
            }
        
        }
        
    
  ungetc(nextChar,cFptr);  //since fgetc() points to the next character,  ungetc() is used to return the original (current) character before each iteration  
        
}
fclose(cFptr);  // close file
fclose(oFptr);

}

return 0;

}

 

