#include <stdio.h> //Index number is AA1711
#include<string.h>

// here I generate function for encryption part it is work for both capital and simple letters.
void encriptionAlgo(char plainText[],int key,char cipherText[]){

    for(int i=0;i<strlen(plainText);i++){

        if(plainText[i]>=65 && plainText[i]<=90)
            cipherText[i]=((plainText[i]-65+key)%26)+65;

        else if (plainText[i]>=97 && plainText[i]<=122)
            cipherText[i]=((plainText[i]-97+key)%26)+97;

        else
            cipherText[i] =plainText[i];
    }
    cipherText[strlen(plainText)] = '\0';
}
// here I generate function for decryption part it is work for both capital and simple letters.
void decriptionAlgo(char cipherText[], int key, char plainText[]){
    for(int i=0;i<strlen(cipherText);i++){
        if(cipherText[i]>=65 && cipherText[i]<=90 && key > (cipherText[i]-65))
            plainText[i]=((cipherText[i]-65-key)%26)+90;
        else if(cipherText[i]>=65 && cipherText[i]<=90)
            plainText[i]=((cipherText[i]-65-key)%26)+65;

        else if(cipherText[i]>=97 && cipherText[i]<=122 && key > (cipherText[i]-97))
            plainText[i]=((cipherText[i]-97-key)%26)+122;
        else if (cipherText[i]>=97 && cipherText[i]<=122)
            plainText[i]=((cipherText[i]-97-key)%26)+97;

        else
            plainText[i] =cipherText[i];
    }
    plainText[strlen(cipherText)] = '\0';
}
//these functions are only use to decorate my terminal. by the way,it is not neccasary to code.
void red() {
    printf("\033[1;31m");
}
void green() {
    printf("\033[0;32m");
}
void lightGreen(){
    printf("\033[0;92m");
}
void cyan(){
    printf("\033[0;96m");
}
void topic(){
    printf("\033[1;5;92m");
}
void reset() {
    printf("\033[0m");
}
//Here is the my main function in this I implement the all function I created.
int main(void) {
    int key;
    char plainText[50];//initialize the char array for the Plain text.
    char cipherText[50];//initialize the char array for the cipher text.
    int number =0;//declare the int for run the main menu.

    while(number != 3){//use while loop for simple main menu.

        topic();
        printf("\n\n\t\tImplement Caesar cipher using \"C\" programming\n");
        red();
        printf("\t\t----------------------------------------------\n\n");
        green();
        printf("\t1.Get Caesar Cipher using Encryption Algorithm\n");
        printf("\t2.Get Plain Text using Decryption Algorithm\n");
        printf("\t3.Quit\n\n");
        lightGreen();
        printf("Enter Preferred Number to Continue : ");
        red();
        int sc =1;
        fflush(stdin); //reset the scanf function.
        sc = scanf("%d", &number);
        cyan();

        if(number == 1){//This is the encryption part in menu.
            reset();
            printf("\nEnter plain text : ");
            cyan();
            fgets(plainText, sizeof(plainText), stdin);
            fgets(plainText, sizeof(plainText), stdin);
            reset();
            printf("\nenter the shift key value :");
            scanf("%d",&key);
            encriptionAlgo(plainText,key,cipherText);
            reset();
            printf("\nCiper Text is : ");
            cyan();
            puts(cipherText);
            continue;
        }

        else if(number == 2){//This is the decryption part in menu.
            reset();
            printf("\nEnter cipher text : ");
            cyan();
            fgets(cipherText, sizeof(cipherText), stdin);
            fgets(cipherText, sizeof(cipherText), stdin);
            reset();
            printf("\nenter the shift key value : ");
            scanf("%d",&key);
            decriptionAlgo(cipherText, key, plainText);
            printf("\nPlain Text is : ");
            cyan();
            puts(plainText);
            continue;
        }
        else {
            if(number == 3)//Quit in the menu.
                printf("Thank you!!!");

            else if(sc ==0){//display error when insert non int.
                red();
                printf("\nEnter only Number");
                reset();
                //continue;
            }
            else{//display error when insert other number instead of 1,2,3.
                red();
                printf("\nEnter Valid Number ");
                reset();
                continue;
            }
        }
    }
    return 0;
}
