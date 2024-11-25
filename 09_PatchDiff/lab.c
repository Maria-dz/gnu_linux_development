#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int check_all(int i, int j, int **rooms, int m, int n){
    int indices[] = {0, 1, 2, 3}; 
    int c = 4;
    int ind = rand() % 4;
    for (int k = c - 1; k > 0;k--) {
        int r = rand() % (k + 1);
        int temp = indices[k];
        indices[k] = indices[r];
        indices[r] = temp;
    }
    bool saw0 = false;
    bool saw1 = false;
    bool saw2 = false;
    bool saw3 = false;
    while (true){
        if (saw0 && saw1 && saw2 && saw3){
            break;
        }
        int ind = rand() % 4;
        switch (ind) {
            case 0:
                saw0 = true;
                if ((j < n-1) && (rooms[i][j+1]==-1)){
                    return 1;
                    break;
                };
            case 1:
                saw1 = true;
                if ((j > 0) && (rooms[i][j-1]==-1)){
                    return 3;
                    break;
                };
            case 2:
                saw2 = true;
                if ((i < m-1) && (rooms[i+1][j]==-1)){
                    return 2;
                    break;
                };
            case 3:
                saw3 = true;
                if ((i > 0) && (rooms[i-1][j]==-1)){
                    return 0;
                    break;
                };
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    int m = 6;
    int n = 6; 
    char wall = '#';
    char space = '.';

    char **matrixMatrices = (char **)malloc((m*2 + 1) * sizeof(char*));
    for (int i = 0; i < (m*2 + 1); i++) {
        matrixMatrices[i] = (char *)malloc((n*2 + 1) * sizeof(char));
    };

    int **rooms = (int **)malloc((m) * sizeof(int*));
    for (int i = 0; i < (m); i++) {
        rooms[i] = (int *)malloc((n) * sizeof(int));
    };
   
    for (int i = 0; i < m; i+=1){
        for (int j = 0; j < n; j+=1){
            rooms[i][j] = -1;
        }
    }

    for (int i = 0; i < m*2 + 1; i+=1) {
        if ((i == 0) || (i == m*2)){
            for (int j = 0; j < n*2 + 1; j+=1) {
                matrixMatrices[i][j] = wall;
            }
        }
        else {    
            if (i % 2 == 0){
                for (int j = 0; j < n*2 + 1; j+=2) {
                    matrixMatrices[i][j] = wall;
                }
            }
            else{
                for (int j = 1; j < n*2 + 1; j+=2) {
                    matrixMatrices[i][j] = space;
                }
            }
            matrixMatrices[i][0] = wall;
            matrixMatrices[i][n*2] = wall;
            };
        }
    int i = 0;
    int j = 0;
    int next_im = 0; 
    int next_jm = 0;

    while (true){
        int status = check_all(i, j, rooms, m , n);
         
        if (status == -1){
            rooms[i][j]=4;
            int sum = 0;
            for (int im = 0; im < m; im+=1){
                for (int jm = 0; jm < n; jm+=1){
                    if (rooms[im][jm] == rand() % 4) {
                        next_im = im;
                        next_jm = jm;
                    }
                    if (rooms[im][jm] == -1){
                        i = next_im;
                        j = next_jm;
                        sum ++;
                        break;
                    }
                }
                if (sum != 0){
                    break;
                }
            }
            if (sum == 0){
                break;
            }
        }
        else if (status == 0){
            rooms[i][j] = 0;
            i -= 1;
        }
        else if (status == 1){
            rooms[i][j] = 1;
            j += 1;
        }
        else if (status == 2){
            rooms[i][j] = 2;
            i += 1;
        }
        else if (status == 3){
            rooms[i][j] = 3;
            j -= 1;
        }
    }

    int ir = 0;
    int jr = 0;

    for (int i = 1; i < m*2; i+=1) {
        int jr = 0;
        if (i % 2 == 1){
            for (int j = 2; j < n*2 ; j+=2) {
                if ((rooms[ir][jr] == 1) || (rooms[ir][jr+1] == 3) ){
                    matrixMatrices[i][j] = space;
                    jr++;

                }
                else {
                    matrixMatrices[i][j] = wall;
                    jr++;
                }
            }
            ir++;
        }
        else{
            for (int j = 1; j < n*2 ; j+=2) {
                if ((rooms[ir-1][jr] == 2) || (rooms[ir][jr] == 0) || (rooms[ir][jr] ==4 ) || (rooms[ir-1][jr] == 4)){
                    matrixMatrices[i][j] = space;
                    jr++;               
                }
                else {
                matrixMatrices[i][j] = wall;
                jr++;

                }
            }
        }
    }
    
    for (int i = 0; i < m*2 + 1; i+=1){
        for (int j = 0; j < n*2 + 1; j+=1){
            printf("%c",matrixMatrices[i][j]);
        }
        printf("\n");
    }


}
