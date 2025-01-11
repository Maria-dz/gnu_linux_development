#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main() {
    setlocale(LC_ALL, "");
    bindtextdomain("guess", LOCALE_PATH);
    textdomain("guess");

    int low = 1;
    int high = 100;
    int mid;
    char response[200];

    printf(_("Choose a number in range 1 - 100\n"));

    while (low <= high) {
        mid = (low + high) / 2;
        printf(_("Is your number greater than %d? Answer 'yes' or 'no': "), mid);

        scanf("%s", response);

	if (strcmp(response, _("yes"))==0) {
            low = mid + 1;
        } else if (strcmp(response, _("no"))==0) {
            high = mid - 1;
        } else {
            printf(_("Incorrect format\n"));
        }

        if (low > high) {
            printf(_("Your number is: %d\n"), mid);
            break;
        }
    }
    return 0;
}
