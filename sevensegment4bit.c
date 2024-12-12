#include <stdio.h>

// Status segmen A-G berdasarkan angka 0-9
const char* segmen[10] = {
    "A=1 B=1 C=1 D=1 E=1 F=1 G=0", // 0
    "A=0 B=1 C=1 D=0 E=0 F=0 G=0", // 1
    "A=1 B=1 C=0 D=1 E=1 F=0 G=1", // 2
    "A=1 B=1 C=1 D=1 E=0 F=0 G=1", // 3
    "A=0 B=1 C=1 D=0 E=0 F=1 G=1", // 4
    "A=1 B=0 C=1 D=1 E=0 F=1 G=1", // 5
    "A=1 B=0 C=1 D=1 E=1 F=1 G=1", // 6
    "A=1 B=1 C=1 D=0 E=0 F=0 G=0", // 7
    "A=1 B=1 C=1 D=1 E=1 F=1 G=1", // 8
    "A=1 B=1 C=1 D=1 E=0 F=1 G=1"  // 9
};

// Pola tampilan 7-segmen
const char* display[10] = {
    " _ \n| |\n|_|", // 0
    "   \n  |\n  |", // 1
    " _ \n _|\n|_ ", // 2
    " _ \n _|\n _|", // 3
    "   \n|_|\n  |", // 4
    " _ \n|_ \n _|", // 5
    " _ \n|_ \n|_|", // 6
    " _ \n  |\n  |", // 7
    " _ \n|_|\n|_|", // 8
    " _ \n|_|\n _|"  // 9
};

// Fungsi untuk menampilkan status segmen dan angka digital
void tampilkanSegment(int w, int x, int y, int z) {
    int angka = (w << 3) | (x << 2) | (y << 1) | z;

    if (angka >= 0 && angka <= 9) {
        printf("Input W=%d X=%d Y=%d Z=%d menghasilkan angka %d\n", w, x, y, z, angka);
        printf("Status Segmen: %s\n", segmen[angka]);
        printf("Tampilan digital:\n");
        printf("%s\n", display[angka]);
    } else {
        printf("Input W=%d X=%d Y=%d Z=%d tidak valid (bukan angka 0-9)\n", w, x, y, z);
    }
}

int main() {
    int w, x, y, z;

    while (1) {
        printf("Masukkan nilai W, X, Y, Z (0 atau 1) atau -1 untuk keluar: ");
        scanf("%d %d %d %d", &w, &x, &y, &z);

        if (w == -1 || x == -1 || y == -1 || z == -1) {
            printf("Keluar dari program.\n");
            break;
        }

        if ((w == 0 || w == 1) && (x == 0 || x == 1) && (y == 0 || y == 1) && (z == 0 || z == 1)) {
            tampilkanSegment(w, x, y, z);
        } else {
            printf("Input tidak valid. Harap masukkan nilai 0 atau 1 untuk W, X, Y, Z.\n");
        }

        printf("\n");
    }

    return 0;
}