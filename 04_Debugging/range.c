#include <stdio.h>
#include <stdlib.h>

void print_progression(int M, int N, int S){
    int j = 0;
    for (int i = M; i < N; i+=S) {
            j++;
            printf("%d\n", i);
            
        }; 
}

int main(int argc, char *argv[]){
    if (argc == 1) {
        printf("help");
    }
    else if (argc == 2) {
        int N = atoi(argv[1]);
        print_progression(0, N, 1);
 
    }
    else if (argc == 3) {
        int M = atoi(argv[1]);
        int N = atoi(argv[2]);
        print_progression(M, N, 1);
        
    }
    else if (argc == 4) {
        int M = atoi(argv[1]);
        int N = atoi(argv[2]);
        int S = atoi(argv[3]);
        print_progression(M, N, S);
        
    }
    return 0;

}
