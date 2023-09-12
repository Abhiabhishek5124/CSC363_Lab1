// Abhishek Shrestha         nku email : shresthaa5@nku.edu     LAB 2   CSC 362


#include <stdio.h>
#include <ctype.h>

int main(){

    // declaration of all the variables 
    char fileName1[30], fileName2[30], isCaseSensitive, nonLettersCompare, char1, char2, charActive1, charActive2;

    FILE *file1, *file2;
    int location=0, error=0;

    printf("Input filename1: ");
    scanf("%s", fileName1);

    printf("Input filename2: ");
    scanf("%s", fileName2);
    printf("Case sensitive? (Y/N): ");
    scanf(" %c", &isCaseSensitive);

    printf("Match non-letters? (Y/N): ");
    scanf(" %c", &nonLettersCompare);

// Opening files for reading
    file1= fopen(fileName1, "r");
    file2=fopen(fileName2,"r");

// checking if file opening was successfull
    if (file1==NULL || file2==NULL){
        printf("Error opening the files.");
        return 1;
    }

// reading characters from both files 
    char1=getc(file1);
    char2=getc(file2);

// comparing the characters until any of the file ends and no error has found
    while(char1!=EOF&&char2!=EOF&&error==0){
        location++; 
        // case where both characters are alphabetic
        if(isalpha(char1)&&isalpha(char2)){
            if (isCaseSensitive == 'N'){
                char1=tolower(char1);
                char2=tolower(char2);
            }
            if (char1!=char2){
                if ((isCaseSensitive=='Y') && (tolower(char1)==tolower(char2))){
                    error=1; //two same characters but different case
                
                }else{
                    error=2; //two different letters
                }
    
            }
        }

        
        else if((!isalpha(char1) && isalpha(char2)) || (isalpha(char1)&& !isalpha(char2))){
            error=3;//letter and non-letter mismatch
        }else if (nonLettersCompare=='Y' & char1!=char2){
            error=4;//two diffeent non letters
        }
// variable just assigned with the characters to print which is showing error
        charActive1=char1;
        charActive2=char2;

        char1=getc(file1);
        char2=getc(file2); 
    }
// checking for file length difference
    if (error==0){
        if (char1!=EOF){
            error=5;
        }else if (char2!=EOF){
            error=6;
        }
    }

// closing files
    fclose(file1);
    fclose(file2);


// printing the result based on error code
    switch (error){
        case 0:
            printf("Files are the same with length of %d.\n",location);
            break;
        case 1:
            printf("Mismatched case at %d with %s having %c and %s having %c\n", location,fileName1, charActive1, fileName2, charActive2);
            break;
        case 2:
            printf("Mismatched two different letters at %d with %s having %c and %s having %c\n", location,fileName1, charActive1, fileName2, charActive2);
            break;
        case 3:
            printf("Mismatched letter/non-letter at %d with %s having %c and %s having %c \n",location,fileName1, charActive1, fileName2, charActive2);
            break;
        case 4:
            printf("Mismatched two different non-letters at %d with %s having %c and %s having %c \n",location,fileName1, charActive1, fileName2, charActive2);
            break;
        case 5:
            printf("First file is longer than second file\n");
            break;
        case 6:
            printf("Second file is longer than first file\n");
            break;
        
        default:
            break;
    }
    
    return 0;
}



// Output:
// 1. 
// Input filename1: p1in4a.txt  
// Input filename2: p1in4b.txt
// Case sensitive? (Y/N): N
// Match non-letters? (Y/N): N
// Files are the same with length of 118

// 2.
// Input filename1: p1in5a.txt
// Input filename2: p1in5b.txt
// Case sensitive? (Y/N): Y
// Match non-letters? (Y/N): N
// Mismatched case at 114 with p1in5a.txt having b and p1in5b.txt having B


// 3.
// Input filename1: p1in6a.txt
// Input filename2: p1in6b.txt
// Case sensitive? (Y/N): N
// Match non-letters? (Y/N): N
// First file is longer than second file

//4.
// Input filename1: p1in7a.txt
// Input filename2: p1in7b.txt
// Case sensitive? (Y/N): N 
// Match non-letters? (Y/N): N
// Second file is longer than first file

// 5.
// Input filename1: p1in8a.txt
// Input filename2: p1in8b.txt
// Case sensitive? (Y/N): N
// Match non-letters? (Y/N): Y
// Mismatched two different non-letters at 4 with p1in8a.txt having - and p1in8b.txt having :


