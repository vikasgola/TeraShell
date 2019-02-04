#ifndef _COLORS_H
#define _COLORS_H

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define color_red(x) KRED <<x<<RST
#define color_green(x) KGRN <<x<< RST
#define color_yellow(x) KYEL <<x<< RST
#define color_blue(x) KBLU <<x<< RST
#define color_magenta(x) KMAG <<x<< RST
#define color_cynaide(x) KCYN <<x<< RST
#define color_white(x) KWHT <<x<< RST

#define bold(x) "\x1B[1m" x<< RST
#define undl(x) "\x1B[4m" x<< RST

#endif  /* _COLORS_ */