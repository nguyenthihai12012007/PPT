#ifndef MENU_H
#define MENU_H

void menu(void);
void clearInputBuffer(void);
void pauseScreen(void);

void menu_hoocner(void);
void xuLyMenuHoocner(void);

void menu_maclaurin(void);
void xulyMenuMaclaurin(void);

void menu_tachnghiem(void);
void xulyMenuTachNghiem();

void menu_timnghiem(void);
void xulyMenuTimNghiem();

void hoocner1(void);
void hoocnertq(void);
void sinx();
void cosx();
void emux();
void dinhly3();
void dinhly4();
double f(double x);
void chiadoi();
double g1(double x);
double dg1(double x);
double g2(double x);
double dg2(double x);
double g3(double x);
double dg3(double x);
double lap(double x, double EPS, double (*g)(double));
void PP_lap();
double f1(double x);
double df1(double x);
double ddf1(double x);
double f2(double x);
double df2(double x);
double ddf2(double x);
double f3(double x);
double df3(double x);
double ddf3(double x);
void PP_tiep_tuyen();
double f1a(double x);
double f2a(double x);
double f3a(double x);
void PP_day_cung();



#endif