#include <stdio.h>//Index number is AA1711
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MX 5 // we are using 5 by 5 matrix.
int choice;

//this function does the remove remove duplicates in string.
void removeDuplicates(char str[]){
    int hash[256]        =  {0};
    int currentIndex     =  0;
    int lastUniqueIndex  =  0;
    while(*(str+currentIndex)){
        char temp = *(str+currentIndex);
        if(0 == hash[temp]){
            hash[temp] = 1;
            *(str+lastUniqueIndex) = temp;
            lastUniqueIndex++;
        }
        currentIndex++;
    }
    *(str+lastUniqueIndex) = '\0';

}
// this is the function that generate and print output text.
void playfair(char ch1, char ch2, char key[MX][MX]) {
    int i, j, w, x, y, z;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                w = i;
                x = j;
            } else if (ch2 == key[i][j]) {
                y = i;
                z = j;
            }
        }
    }
    //printf("%d%d %d%d",w,x,y,z);
    if (w == y) {
        if(choice==1){
            x = (x + 1) % 5;
            z = (z + 1) % 5;
        }
        else{
            x = ((x - 1) % 5+5)%5;
            z = ((z - 1) % 5+5)%5;
        }
        printf("%c%c", key[w][x], key[y][z]);
    } else if (x == z) {
        if(choice==1){
            w = (w + 1) % 5;
            y = (y + 1) % 5;
        }
        else{
            w = ((w - 1) % 5+5)%5;
            y = ((y - 1) % 5+5)%5;
        }
        printf("%c%c", key[w][x], key[y][z]);
    }
    else {
        printf("%c%c", key[w][z], key[y][x]);
    }
}

//these functions are only use to decorate my terminal. by the way,it is not necessary to code.
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
void magenta(){
    printf("\033[0;35m");
}

int main() {

    while(choice != 3){
        int i, j, k = 0, l, m = 0, n;
        char key[MX][MX], keyminus[25], keystr[10], str[25] = {0};
        //Creating Alphabet char Array.
        char alpa[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        topic();
        printf("\n\n\t\tImplement Caesar cipher using \"C\" programming\n");
        red();
        printf("\t\t----------------------------------------------\n\n");
        green();
        printf("\t1.Get Playfair Cipher using Encryption Algorithm\n");
        printf("\t2.Get Plain Text using Decryption  Algorithm\n");
        printf("\t<Any other number to Quit>\n\n");
        lightGreen();
        printf("Enter Preferred Number to Continue : ");
        red();
        int sc = scanf("%d",&choice);
        if(sc != 1){//error handling that entering other charters.
            red();
            printf("Invalid character!! \033[0;92m \nRun the program again.");
            reset();
            printf(" Thank you!!!");
            break;}
        if(choice!=1 && choice!=2){ //when entering other numbers quit the program.
            printf("Thank you!!!");
            break;
            return 0;
        }

        fflush(stdin);
        reset();
        printf("\nEnter the key : ");

        gets();
        gets(keystr); //get the key string in terminal.
        printf("Enter the text : ");
        cyan();
        gets(str);//get the text string in terminal that you want to Encrypt or Decrypt.
        reset();
        printf("\nCreating 5 By 5 matrix...\n");
        magenta();

        removeDuplicates(keystr);
        n = strlen(keystr);
        //convert the characters to upper text.
        for (i = 0; i < n; i++) {
            if (keystr[i] == 'j') keystr[i] = 'i';
            else if (keystr[i] == 'J') keystr[i] = 'I';
            keystr[i] = toupper(keystr[i]);
        }
        //convert all the characters of plaintext to upper text.
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == 'j') str[i] = 'i';
            else if (str[i] == 'J') str[i] = 'I';
            str[i] = toupper(str[i]);
        }
        // store all characters except key
        j = 0;
        for (i = 0; i < 26; i++) {
            for (k = 0; k < n; k++) {
                if (keystr[k] == alpa[i]) break;
                else if (alpa[i] == 'J') break;
            }
            if (k == n) {
                keyminus[j] = alpa[i];
                j++;
            }
        }
        //construct the key matrix.
        k = 0;
        for (i = 0; i < MX; i++) {
            for (j = 0; j < MX; j++) {
                if (k < n) {
                    key[i][j] = keystr[k];
                    k++;
                } else {
                    key[i][j] = keyminus[m];
                    m++;
                }
                printf("%c ", key[i][j]);
            }
            printf("\n");
        }
        // construct the diagram and convert to cipher text
        reset();
        printf("\nEntered text is\033[0;96m %s\033[0m\nOutput Text is ", str);
        cyan();
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == 'J') str[i] = 'I';
            if (str[i + 1] == '\0') playfair(str[i], 'Z', key);
            else {
                if (str[i + 1] == 'J') str[i + 1] = 'I';
                if (str[i] == str[i + 1]) playfair(str[i], 'Z', key);
                else {
                    playfair(str[i], str[i + 1], key);
                    i++;
                }
            }
        }
        red();
        if(choice==2) printf(" \"Remove unnecessary Z\"");
        reset();
    }
    return 0;
}