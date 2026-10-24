#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char papan[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    
void tampilkanPapan() {
    for (int i = 0; i < 3; i++) {
        printf("%c | %c | %c \n",
            papan[i][0], papan[i][1], papan[i][2]);

        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int cekMenang() {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] != ' ' &&
            papan[i][0] == papan[i][1] &&
            papan[i][1] == papan[i][2])
            return 1;

        if (papan[0][i] != ' ' &&
            papan[0][i] == papan[1][i] &&
            papan[1][i] == papan[2][i])
            return 1;
    }

    if (papan[0][0] != ' ' &&
        papan[0][0] == papan[1][1] &&
        papan[1][1] == papan[2][2])
        return 1;

    if (papan[0][2] != ' ' &&
        papan[0][2] == papan[1][1] &&
        papan[1][1] == papan[2][0])
        return 1;

    return 0;
}

int main() {
    int baris, kolom, giliran;
    char pemain = 'X';

    for (giliran = 0; giliran < 9; giliran++) {
        tampilkanPapan();

        printf("Giliran pemain %c\n", pemain);
        printf("Masukkan baris (1-3): ");
        scanf("%d", &baris);

        printf("Masukkan kolom (1-3): ");
        scanf("%d", &kolom);

        baris--;
        kolom--;

        if (baris < 0 || baris > 2 ||
            kolom < 0 || kolom > 2 ||
            papan[baris][kolom] != ' ') {
            printf("Kotak tidak valid atau sudah terisi!\n");
            giliran--;
            continue;
        }

        papan[baris][kolom] = pemain;

        if (cekMenang()) {
            tampilkanPapan();
            printf("Pemain %c menang!\n", pemain);
            return 0;
        }

        pemain = (pemain == 'X') ? 'O' : 'X';
    }

    tampilkanPapan();
    printf("Permainan seri!\n");

    return 0;
}