#include <iostream>
using namespace std;

int sd[9][9];
int shudu_num = 0, pri_number = 0;
FILE *wri;

// MARK: -Helper Methods:
int generateInteger(const char *string) {
    int integer = 0;
    int multiplier = 1;
    for (unsigned int i = 0; i < strlen(string); i++) {
        if (string[i] > '9' || string[i] < '0') {
            printf("Number Error!\n");
            exit(0);
        }
    }
    for (long int i = strlen(string) - 1; i >= 0; i--) {
        integer += (string[i] - '0') * multiplier;
        multiplier *= 10;
    }
    if (integer <= 0 || integer > 1000000) {
        printf("Number Error!\n");
        exit(0);
    }
    return integer;
}


void pr() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            
            fprintf(wri,"%d", sd[i][j]);
            if (j != 8) {
                fprintf(wri," ");
            }
        }
        fprintf(wri, "\n");
    }
}

int judge(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (sd[x][i] == sd[x][y] && y != i) {
            return 1;
        }
        if (sd[i][y] == sd[x][y] && x != i) {
            return 1;
        }
    }
    int n1 = x / 3;
    int n2 = y / 3;
    n1 *= 3;
    n2 *= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sd[n1 + i][n2 + j] == sd[x][y] && n1 + i != x&&n2 + j != y) {
                return 1;
            }
        }
    }
    return 0;
}


void DFS2(int x, int y) {
    for (int i = 1; i <= 9; i++) {
        sd[x][y] = i;
        if (judge(x, y) == 0) {
            if (x == 8 && y == 8) {
                pr();
                pri_number++;
                if (pri_number == shudu_num) {
                    printf(" ˝∂¿…˙≥…≥…π¶£°\n");
                    exit(0);
                }
                fprintf(wri, "\n");
            }
            else if (y == 8) {
                DFS2(x + 1, 0);
                sd[x + 1][0] = 0;
            }
            else if (y != 8) {
                DFS2(x, y + 1);
                sd[x][y + 1] = 0;
            }
        }
    }
}



void shud(int n) {
    shudu_num = n;
    sd[0][0] = 3;
    pri_number = 0;
    DFS2(0, 1);
}

// MARK: - Constructor:
void construct(const char *string) {
    printf("I am the constructor.\n");
    int integer = generateInteger(string);
    shud(integer);
    
}
