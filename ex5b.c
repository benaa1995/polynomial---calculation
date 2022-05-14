//#include <stdio.h>
//#include <pwd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <unistd.h>
//#include <sys/wait.h>
//
//#define LEN 510
//
////Finding a free organ.
//int freeNum(char *);
////Proper input test.
//bool ifValidString(char *);
////Checking if the polynomial has organs with disappearing.
//bool polynomialWithOrWithoutDisappearing(char *);
////Checking whether the polynomial has mathematical operations.
//bool isThereAMathematicalOperation(char *);
//
////A function that will separate our polynomial by a power rank.
//char *splitString(char *, int);
//
////ex1.
//int howManyLetters(char *);
//
////print the menu.
//void printMenu();
//
////Calculation of how many disappearing.
//int howManyDisappears(char *);
//
////Calculation of polynomial without disappearing.
//void polynomialWithoutDisappearing(char *);
//
////Calculation of polynomial according to parts we divided the polynomial.
//int calculation(char *, int);
//
////Search a comma so we can know what the polynomial is and what the value is.
//int indexComma(char *);
//
////Convert value to int.
//int valueToInt(char *);
//
////Search a disappearing.
//int indexForX(char *, int);
//
////My data structure of all processes so we can collect all the results.
//struct fx {
//    int freeNum;
//    int value;
//    int x1;
//    int x2;
//    int x3;
//    int result;
//} data;
//
//
////int the main We perform the:
////get the input.
////creating shared memory for all processes with a key.
////creating processes as per our need.
////finally freeing up all the resources we used.
//int main() {
//    pid_t son1, son2, son3;
//    key_t key;
//    key = ftok("/tmp", 'b');
//    if (key == -1) {
//        printf("key failed!!\n");
//        exit(EXIT_FAILURE);
//    }
//    struct fx *ptr;
//    int shm_id;
//    if ((shm_id = shmget(key, LEN, IPC_CREAT | IPC_EXCL | 0600)) == -1) {
//        perror("Shared memory");
//        exit(EXIT_FAILURE);
//    }
//    ptr = shmat(shm_id, NULL, 0);
//    if (ptr == (void *) -1) {
//        perror("Shared memory attach");
//        exit(EXIT_FAILURE);
//    }
//    char string[LEN];
//    int polynomialType; //0=Does not exist disappear 1=There are disappearing
//    int quantityDisappears;
//    while (1) {
//        printMenu();
//        fgets(string, LEN, stdin);
//        if (strcmp(string, "done\n") == 0) {
//            printf("The program is over, thank you\n");
//            shmdt(ptr);
//            return 0;
//        }
//        if (howManyLetters(string) == 0 || ifValidString(string) == false) {
//            printf("\x1b[31mInvalid input, please enter correct input\n\033[0m");
//            continue;
//        }
//        data.value = valueToInt(string);
//        data.freeNum = freeNum(string);
//        if (polynomialWithOrWithoutDisappearing(string) == true) {
//            polynomialType = 1;
//        } else {
//            polynomialType = 0;
//        }
//        switch (polynomialType) {
//            case 0:
//                polynomialWithoutDisappearing(string);
//                break;
//            case 1:
//                quantityDisappears = howManyDisappears(string);
//                if (quantityDisappears == 1) {
//                    char *a;
//                    a = splitString(string, quantityDisappears);
//                    son1 = fork();
//                    if (son1 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son1 == 0) {
//                        ptr->result = calculation(a, data.value);
//                        ptr->result = ptr->result + data.freeNum;
//                        return 1;
//                    } else {
//                        wait(NULL);
//                        printf("f(""%d"")""= %d\n", data.value, ptr->result);
//                        data.value = 0;
//                        data.freeNum = 0;
//                        data.result = 0;
//                        shmctl(shm_id, IPC_RMID, NULL);
//                        free(a);
//                    }
//                }
//                if (quantityDisappears == 2) {
//                    char *a, *b;
//                    a = splitString(string, 1);
//                    b = splitString(string, quantityDisappears);
//                    son1 = fork();
//                    if (son1 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son1 == 0) {
//                        ptr->x1 = calculation(a, data.value);
//                        return 1;
//                    }
//                    wait(NULL);
//                    son2 = fork();
//                    if (son2 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son2 == 0) {
//                        ptr->x2 = calculation(b, data.value);
//                        return 1;
//                    }
//                    wait(NULL);
//                    ptr->result = ptr->x1 + ptr->x2 + data.freeNum;
//                    printf("f(""%d"")""= %d\n", data.value, ptr->result);
//                    data.value = 0;
//                    data.freeNum = 0;
//                    data.result = 0;
//                    shmctl(shm_id, IPC_RMID, NULL);
//                    free(a);
//                    free(b);
//                }
//                if (quantityDisappears == 3) {
//                    char *a, *b, *c;
//                    a = splitString(string, 1);
//                    b = splitString(string, 2);
//                    c = splitString(string, quantityDisappears);
//                    son1 = fork();
//                    if (son1 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son1 == 0) {
//                        ptr->x1 = calculation(a, data.value);
//                        return 1;
//                    }
//                    wait(NULL);
//                    son2 = fork();
//                    if (son2 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son2 == 0) {
//                        ptr->x2 = calculation(b, data.value);
//                        return 1;
//                    }
//                    wait(NULL);
//                    son3 = fork();
//                    if (son3 == -1) {
//                        perror("Error fork create\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    if (son3 == 0) {
//                        ptr->x3 = calculation(c, data.value);
//                        return 1;
//                    }
//                    wait(NULL);
//                    ptr->result = ptr->x1 + ptr->x2 + ptr->x3 + data.freeNum;
//                    printf("f(""%d"")""= %d\n", data.value, ptr->result);
//                    data.value = 0;
//                    data.freeNum = 0;
//                    data.result = 0;
//                    shmctl(shm_id, IPC_RMID, NULL);
//                    free(a);
//                    free(b);
//                    free(c);
//                }
//            default:
//                continue;
//        }
//
//    }
//}
//
////Method for calculating a polynomial according to a division we made into a polynomial
////and finally if there is a need for multiplication "*" then we will do it.
//int calculation(char *string, int v) {
//    int res;
//    int multiplication = 0;
//    int numMulti;
//    for (int i = 0; i < strlen(string); i++) {
//        if (string[i] == '*') {
//            multiplication = 1;
//            numMulti = atoi(&string[i - 1]);
//        }
//        if (string[i] == '^') {
//            if (string[i + 1] == '1') {
//                res = v;
//            }
//            if (string[i + 1] == '2') {
//                res = v * v;
//            }
//            if (string[i + 1] == '3') {
//                res = v * v * v;
//            }
//        }
//    }
//    if (multiplication == 1) {
//        res = res * numMulti;
//    }
//    return res;
//}
//
////This function will split the polynomial so that it will be easier for us to calculate the polynomial
////at the end of the calculations.
//char *splitString(char *string, int quantity) {
//    int indexA;
//    int indexB;
//    int indexC;
//    char *newString;
//    if (quantity == 1) {
//        indexA = indexForX(string, quantity);
//        if (string[indexA - 1] != '*') {
//            newString = (char *) malloc(sizeof(char) * 4);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexA], 3);
//            newString[3] = '\0';
//        } else {
//            newString = (char *) malloc(sizeof(char) * 6);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexA - 2], 5);
//            newString[5] = '\0';
//        }
//    }
//    if (quantity == 2) {
//        indexB = indexForX(string, quantity);
//        if (string[indexB - 1] != '*') {
//            newString = (char *) malloc(sizeof(char) * 4);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexB], 3);
//            newString[3] = '\0';
//        } else {
//            newString = (char *) malloc(sizeof(char) * 6);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexB - 2], 5);
//            newString[5] = '\0';
//        }
//    }
//    if (quantity == 3) {
//        indexC = indexForX(string, quantity);
//        if (string[indexC - 1] != '*') {
//            newString = (char *) malloc(sizeof(char) * 4);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexC], 3);
//            newString[3] = '\0';
//        } else {
//            newString = (char *) malloc(sizeof(char) * 6);
//            if (newString == NULL) {
//                fputs("Error allocating memory !!\n", stderr);
//                exit(EXIT_FAILURE);
//            }
//            strncpy(newString, &string[indexC - 2], 5);
//            newString[5] = '\0';
//        }
//    }
//    return newString;
//}
//
//void printMenu() {
//    printf("Please enter the polynomial and entry value in polynomial:\n");
//    printf("As follows ---> Polynomial, Value\n");
//}
//
//int valueToInt(char *string) {
//    int index = indexComma(string);
//    int len = 0;
//    int valueToInt;
//    for (int i = index; i < strlen(string); i++) {
//        if (string[i] != ' ' && string[i] != '\0' && string[i] != '\n') {
//            len++;
//        }
//    }
//    char value[len];
//    strncpy(value, &string[index + 1], len);
//    valueToInt = atoi(value);
//    return valueToInt;
//}
//
//void polynomialWithoutDisappearing(char *string) {
//    int index = indexComma(string);
//    char result[index];
//    if (isThereAMathematicalOperation(string) == false) {
//        strncpy(result, &string[0], index);
//        if (string[strlen(string) - 1] == '\n') {
//            string[strlen(string) - 1] = '\0';
//        }
//        printf("f(""%d"")"": %s\n", data.value, result);
//        return;
//    } else {
//        printf("Invalid input, please enter correct input\n");
//        return;
//    }
//}
//
//int indexComma(char *string) {
//    int index;
//    for (int i = 0; i < strlen(string); i++) {
//        if (string[i] == ',') {
//            index = i;
//        }
//    }
//    return index;
//}
//
//int indexForX(char *string, int quantity) {
//    int indexX;
//    int found = 0;
//    for (int i = 0; i < strlen(string); i++) {
//        if (quantity == 1) {
//            if (string[i] == 'x') {
//                indexX = i;
//                break;
//            }
//        }
//        if (quantity == 2) {
//            if (string[i] == 'x') {
//                found++;
//                if (found == 2) {
//                    indexX = i;
//                    break;
//                }
//            }
//        }
//        if (quantity == 3) {
//            if (string[i] == 'x') {
//                found++;
//                if (found == 3) {
//                    indexX = i;
//                    break;
//                }
//            }
//        }
//    }
//    return indexX;
//}
//
//int freeNum(char *string) {
//    int index = indexComma(string);
//    int len = 0;
//    int num;
//    while (string[index] != '+') {
//        len++;
//        index--;
//    }
//    char temp[len];
//    strncpy(temp, &string[index], len);
//    num = atoi(temp);
//    return num;
//}
//
//
//bool ifValidString(char *string) {
//    int value;
//    if (string[0] == ' ')
//        return false;
//    for (int i = 0; i < strlen(string); i++) {
//        if ((string[i] < '0') || (string[i] > '9')) {
//            if (string[i] != ',' && string[i] != ' ' && string[i] != '+' && string[i] != '*' && string[i] != '^' &&
//                string[i] != 'x' && string[i] != '\n') {
//                return false;
//            }
//        }
//        if (string[i] == ',') {
//            value = 1;
//            if (string[i - 1] == ' ' || string[i + 1] != ' ' || string[i + 2] == ' ')
//                return false;
//            if (string[i - 1] == ',' || string[i + 1] == ',' || string[i - 1] == '+' || string[i - 1] == '-')
//                return false;
//            int lenValue = strlen(string) - i;
//            char validValue[lenValue];
//            strncpy(validValue, &string[i + 2], lenValue);
//            if (isThereAMathematicalOperation(validValue) == true)
//                return false;
//        }
//        if (string[i] == '+' || string[i] == '*') {
//            if (string[i + 1] == '+' || string[i - 1] == '+' || string[i - 1] < '0' || string[i - 1] > '9')
//                return false;
//            if (string[i + 1] == '*' || string[i - 1] == '*' || string[i - 1] < '0' || string[i - 1] > '9')
//                return false;
//            if (string[i + 1] == ' ' || string[i - 1] == ' ' || string[i - 1] < '0' || string[i - 1] > '9')
//                return false;
//        }
//        if (string[i] == '^' && string[i - 1] != 'x') {
//            return false;
//        }
//        if (string[i] == '^' && string[i + 1] > '3') {
//            return false;
//        }
//    }
//    if (value != 1)
//        return false;
//
//    return true;
//}
//
//bool isThereAMathematicalOperation(char *string) {
//    for (int i = 0; i < strlen(string); i++) {
//        if (string[i] == '+')
//            return true;
//        if (string[i] == '*')
//            return true;
//    }
//    return false;
//}
//
//bool polynomialWithOrWithoutDisappearing(char *string) {
//    for (int i = 0; i < strlen(string); i++) {
//        if (string[i] == 'x')
//            return true;
//    }
//    return false;
//}
//
//int howManyDisappears(char *string) {
//    int quantityDisappears = 0, firsDegree, secondDegree, thirdDegree = 0;
//    for (int i = 0; i < strlen(string); i++) {
//        if (string[i] == '^') {
//            if (string[i + 1] == '1' && firsDegree != 1) {
//                quantityDisappears++;
//                firsDegree = 1;
//            }
//            if (string[i + 1] == '2' && secondDegree != 1) {
//                quantityDisappears++;
//                secondDegree = 1;
//            }
//            if (string[i + 1] == '3' && thirdDegree != 1) {
//                quantityDisappears++;
//                thirdDegree = 1;
//            }
//        }
//    }
//    return quantityDisappears;
//}
//
////ex1
//int howManyWords(char *sentences) {
//    int i;
//    int counterOfWords = 0;
//    int counterOfLetters = 0;
//    for (i = 0; i <= strlen(sentences); i++) {
//        if (sentences[i] != '\n' && sentences[i] != '\0' && sentences[i] != ' ') {
//            counterOfLetters++;
//        }
//        if (sentences[i] == ' ' || sentences[i] == '\n' || sentences[i] == '\0') {
//            if (counterOfLetters > 0) {
//                counterOfWords++;
//                counterOfLetters = 0;
//            }
//        }
//    }
//    return counterOfWords;
//}
//
//int howManyLetters(char *sentences) {
//    int i;
//    int counterOfLetters = 0;
//    int counter = 0;
//    for (i = 0; i < strlen(sentences); i++) {
//        if (sentences[i] != '\n' && sentences[i] != '\0' && sentences[i] != ' ') {
//            counterOfLetters++;
//        }
//        if (sentences[i] == ' ' || sentences[i] == '\n' || sentences[i] == '\0') {
//            if (counterOfLetters > 0) {
//                counter += counterOfLetters;
//            }
//        }
//    }
//    counter += howManyWords(sentences);
//    return counter;
//}
