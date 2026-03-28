#include <stdio.h>
#include "menu.h"

void menu_hoocner() {
    printf("--------SO DO HOOCNER--------\n");
    printf("1.Gia tri\n");
    printf("2.Tong quat\n");
    printf("0. Thoat chuong trinh\n");
    printf("Chon: ");
}

void xuLyMenuHoocner() {
    int subChoice;
    do {
        menu_hoocner();
        printf("\nNhap lua chon: ");
        scanf("%d", &subChoice);

        switch (subChoice) {
            case 1:
                hoocner1();
                break;
            case 2:
                hoocnertq();
                break;
            case 0:
                printf("Quay lai menu chinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (subChoice != 0);
}

void xulyMenuMaclaurin() {
    int subChoice;
    do {
        menu_maclaurin();
        printf("\nNhap lua chon: ");
        scanf("%d",&subChoice);

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

void menu_maclaurin() {
    printf("--------KHAI TRIEN HAM--------\n");
    printf("1.Ham sinx\n");
    printf("2.Ham cos\n");
    printf("3.Ham e mu x\n");   
    printf("0. Thoat chuong trinh\n");
    printf("Chon: ");
}

void menu_tachnghiem() {
    printf("--------TACH NGHIEM--------\n");
    printf("1.Dinh ly 3\n");
    printf("2.Dinh ly 4\n");
    printf("3.Dinh ly 5\n");   
    printf("0. Thoat chuong trinh\n");
    printf("Chon: ");
}

void xulyMenuTachNghiem() {
    int subChoice;
    do {
        menu_tachnghiem();
        printf("\nNhap lua chon: ");
        scanf("%d",&subChoice);

        switch (subChoice) {
        case 1:
            dinhly3();
            break;
        case 2:
            dinhly4();
            break;
        case 3:
            //dinhly5();
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
    printf("----------TIM NGHIEM-----------\n");
    printf("1.Phuong phap chia doi\n");
    printf("2.Phuong phap lap\n");
    printf("3.Phuong phap tiep tuyen\n");
    printf("4.Phuong phap day cung\n");
    printf("0. Thoat chuong trinh\n");
    printf("Chon: ");
}

void xulyMenuTimNghiem() {
    int subChoice;
    do {
        menu_timnghiem();
        printf("\nNhap lua chon: ");
        scanf("%d",&subChoice);

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
    printf("----------PHUONG PHAP TINH-----------\n");
    printf("1. So do Hoocner \n");
    printf("2. Khai trien ham theo Maclaurin\n");
    printf("3. Tach nghiem \n");
    printf("4. Tim nghiem\n");
    printf("0. Thoat chuong trinh\n");
    printf("Chon: ");
}