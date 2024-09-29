#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


#define DX 7
#define DY 3


int main(int argc, char *argv[]) {
        WINDOW *frame, *win;
        FILE *file;
        int cur_size = 1;
        int line_count = 0;
        int start = 0;
        int finish = 6; 
        char **lines = malloc(cur_size * sizeof(char *));
        char *file_name = argv[1];
        

        int c = 0;

        setlocale(LC_ALL, "");
        initscr();
        noecho();
        cbreak();
        printw("File: %s\n ", file_name);
        refresh();

        char buffer[COLS - 2*DX-2];
        
        file = fopen(file_name, "r");

        while (fgets(buffer, sizeof(buffer), file)) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            };
            if (line_count < cur_size) {
                lines[line_count] = strdup(buffer);
            } else { 
                cur_size = cur_size * 3;
                lines = realloc(lines, cur_size * sizeof(char *));
                lines[line_count] = strdup(buffer);
            }
            line_count++;
        }

        frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
        box(frame, 0, 0);
        mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), "Рамка");
        wrefresh(frame);

        win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
        keypad(win, TRUE);
        scrollok (win, TRUE);
        for(int i = start; i < LINES - 2*DY - 2 + start; i++) {
                wprintw(win, "%s\n", lines[i]);
                };

        while((c = wgetch(win)) != 27){
                if (c == ' '){
                    start ++;
                    finish = LINES - 2*DY - 2 + start;
                    werase(win);
                    if (finish >= line_count){
                       finish = line_count - 1;
                    }
                    for(int i = start; i < finish; i++) {
                    wprintw(win, "%s\n", lines[i]);
                    };
                }

        };
        delwin(win);
        delwin(frame);
        endwin();
        return 0;
}