#include <stdio.h>
#include "menu.h"

void menu_hoocner() {
    printf("\n-------- SO DO HOOCNER --------\n");
    printf("1.Gia tri\n");
    printf("2.Tong quat\n");
    printf("0. Quay lai\n");
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void pauseScreen(void) {
    clearInputBuffer();
    printf("\nNhan Enter de tiep tuc...");
    fflush(stdout);
    getchar();
    printf("\n");
}

void xuLyMenuHoocner() {
    int subChoice;
    do {
        menu_hoocner();
        printf("\nNhap lua chon: ");
        if (scanf("%d", &subChoice) != 1) {
            printf("Lua chon khong hop le!\n");
            clearInputBuffer();
            continue;
        }

        switch (subChoice) {
            case 1:
                hoocner1();
                break;
            case 2:
                hoocnertq();
                break;
            case 0:
                printf("Quay lai menu chinh.\n\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (subChoice != 0);
}

void menu_maclaurin() {
    printf("\n-------- KHAI TRIEN HAM --------\n");
    printf("1. Ham sinx\n");
    printf("2. Ham cos\n");
    printf("3. Ham e^x\n");   
    printf("0. Thoat chuong trinh\n");
}

void xulyMenuMaclaurin() {
    int subChoice;
    do {
        menu_maclaurin();
        printf("\nNhap lua chon: ");
        if (scanf("%d", &subChoice) != 1) {
            printf("Lua chon khong hop le!\n");
            clearInputBuffer();
            continue;
        }

        switch (subChoice) {
        case 1:
            sinx();
            break;
        case 2:
            cosx();
            break;
        case 3:
            emux();
            break;
        case 0:
            printf("Quay lai menu chinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (subChoice != 0);
}

void menu_tachnghiem() {
    printf("\n-------- TACH NGHIEM --------\n");
    printf("1. Dinh ly 3\n");
    printf("2. Dinh ly 4\n");
    printf("0. Thoat chuong trinh\n");
}

void xulyMenuTachNghiem() {
    int subChoice;
    do {
        menu_tachnghiem();
        printf("\nNhap lua chon: ");
        if (scanf("%d", &subChoice) != 1) {
            printf("Lua chon khong hop le!\n");
            clearInputBuffer();
            continue;
        }

        switch (subChoice) {
        case 1:
            dinhly3();
            break;
        case 2:
            dinhly4();
            break;
        case 0:
            printf("Quay lai menu chinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (subChoice != 0);
}

void menu_timnghiem() {
    printf("\n---------- TIM NGHIEM -----------\n");
    printf("1. Phuong phap chia doi\n");
    printf("2. Phuong phap lap\n");
    printf("3. Phuong phap tiep tuyen\n");
    printf("4. Phuong phap day cung\n");
    printf("0. Thoat chuong trinh\n");
}

void xulyMenuTimNghiem() {
    int subChoice;
    do {
        menu_timnghiem();
        printf("\nNhap lua chon: ");
        if (scanf("%d", &subChoice) != 1) {
            printf("Lua chon khong hop le!\n");
            clearInputBuffer();
            continue;
        }

        switch (subChoice) {
        case 1:
            chiadoi();
            break;
        case 2:
            PP_lap();
            break;
        case 3:
            PP_tiep_tuyen();
            break;
        case 4:
            PP_day_cung();
            break;
        case 0:
            printf("Quay lai menu chinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (subChoice != 0);
}

void menu() {
    printf("\n---------- PHUONG PHAP TINH -----------\n");
    printf("1. So do Hoocner \n");
    printf("2. Khai trien ham theo Maclaurin\n");
    printf("3. Tach nghiem \n");
    printf("4. Tim nghiem\n");
    printf("0. Thoat chuong trinh\n");
    printf("\nNhap lua chon: ");
}
