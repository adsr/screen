#ifndef SCREEN_UTMP_H
#define SCREEN_UTMP_H

#include "config.h"

#include "window.h"

#ifdef UTMPOK
void  InitUtmp (void);
void  RemoveLoginSlot (void);
void  RestoreLoginSlot (void);
int   SetUtmp (Window *);
int   RemoveUtmp (Window *);
#endif /* UTMPOK */
void  SlotToggle (bool);
#ifdef CAREFULUTMP
void   CarefulUtmp (void);
#else
# define CarefulUtmp()  /* nothing */
#endif /* CAREFULUTMP */

#endif /* SCREEN_UTMP_H */
