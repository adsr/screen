/* Copyright (c) 1993-2000
 *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)
 *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)
 * Copyright (c) 1987 Oliver Laumann
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (see the file COPYING); if not, see
 * http://www.gnu.org/licenses/, or contact Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 ****************************************************************
 * $Id$ GNU
 */





/**********************************************************************
 *
 *	User Configuration Section
 */

/*
 * Maximum of simultaneously allowed windows per screen session.
 */
#ifndef MAXWIN
# define MAXWIN 100
#endif

/*
 * Define SOCKDIR to be the directory to contain the named sockets
 * screen creates. This should be in a common subdirectory, such as
 * /usr/local or /tmp. It makes things a little more secure if you
 * choose a directory which is not writable by everyone or where the
 * "sticky" bit is on, but this isn't required.
 * If SOCKDIR is not defined screen will put the named sockets in
 * the user's home directory. Notice that this can cause you problems
 * if some user's HOME directories are AFS- or NFS-mounted. Especially
 * AFS is unlikely to support named sockets.
 *
 * Screen will name the subdirectories "S-$USER" (e.g /tmp/S-davison).
 */
#undef SOCKDIR

/*
 * Define this if the SOCKDIR is not shared between hosts.
 */
#define SOCKDIR_IS_LOCAL_TO_HOST

/*
 * Screen can look for the environment variable $SYSSCREENRC and -if it
 * exists- load the file specified in that variable as global screenrc.
 * If you want to enable this feature, define ALLOW_SYSSCREENRC to one (1).
 * Otherwise ETCSCREENRC is always loaded.
 */
#define ALLOW_SYSSCREENRC 1

/*
 * define PTYMODE if you do not like the default of 0622, which allows
 * public write to your pty.
 * define PTYGROUP to some numerical group-id if you do not want the
 * tty to be in "your" group.
 * Note, screen is unable to change mode or group of the pty if it
 * is not installed with sufficient privilege. (e.g. set-uid-root)
 * define PTYROFS if the /dev/pty devices are mounted on a read-only
 * filesystem so screen should not even attempt to set mode or group
 * even if running as root (e.g. on TiVo).
 */
#undef PTYMODE
#undef PTYGROUP
#undef PTYROFS

/*
 * If screen is NOT installed set-uid root, screen can provide tty
 * security by exclusively locking the ptys.  While this keeps other
 * users from opening your ptys, it also keeps your own subprocesses
 * from being able to open /dev/tty.  Define LOCKPTY to add this
 * exclusive locking.
 */
#undef LOCKPTY

/*
 * define BUILTIN_TELNET to enable built in telnte support
 */
#undef BUILTIN_TELNET

/*
 * If screen is installed with permissions to update /etc/utmp (such
 * as if it is installed set-uid root), define UTMPOK.
 */
#define UTMPOK

/* Set LOGINDEFAULT to one (1)
 * if you want entries added to /etc/utmp by default, else set it to
 * zero (0).
 * LOGINDEFAULT will be one (1) whenever LOGOUTOK is undefined!
 */
#define LOGINDEFAULT	1

/* Set LOGOUTOK to one (1)
 * if you want the user to be able to log her/his windows out.
 * (Meaning: They are there, but not visible in /etc/utmp).
 * Disabling this feature only makes sense if you have a secure /etc/utmp
 * database.
 * Negative examples: suns usually have a world writable utmp file,
 * xterm will run perfectly without s-bit.
 *
 * If LOGOUTOK is undefined and UTMPOK is defined, all windows are
 * initially and permanently logged in.
 *
 * Set CAREFULUTMP to one (1) if you want that users have at least one
 * window per screen session logged in.
 */
#define LOGOUTOK 1
#undef CAREFULUTMP

/*
 * to lower the interrupt load on the host machine, you may want to
 * adjust the VMIN and VTIME settings used for plain tty windows.
 * See the termio(4) manual page (Non-Canonical Mode Input Processing)
 * for details.
 * if undefined, VMIN=1, VTIME=0 is used as a default - this gives you
 * best user responsiveness, but highest interrupt frequency.
 * (Do not bother, if you are not using plain tty windows.)
 */
#define TTYVMIN 100
#define TTYVTIME 2

/*
 * Some terminals, e.g. Wyse 120, use a bitfield to select attributes.
 * This doesn't work with the standard so/ul/m? terminal entries,
 * because they will cancel each other out.
 * On TERMINFO machines, "sa" (sgr) may work. If you want screen
 * to switch attributes only with sgr, define USE_SGR.
 * This is *not* recomended, do this only if you must.
 */
#undef USE_SGR


/*
 * Define USE_PAM if your system supports PAM (Pluggable Authentication
 * Modules) and you want screen to use it instead of calling crypt().
 * (You may also need to add -lpam to LIBS in the Makefile.)
 */
#undef USE_PAM

/**********************************************************************
 *
 *	End of User Configuration Section
 *
 *      Rest of this file is modified by 'configure'
 *      Change at your own risk!
 *
 */

/*
 * Define POSIX if your system supports IEEE Std 1003.1-1988 (POSIX).
 */
#undef POSIX

/*
 * Define TERMIO if you have struct termio instead of struct sgttyb.
 * This is usually the case for SVID systems, where BSD uses sgttyb.
 * POSIX systems should define this anyway, even though they use
 * struct termios.
 */
#undef TERMIO

/*
 * Define CYTERMIO if you have cyrillic termio modes.
 */
#undef CYTERMIO

/*
 * If your library does not define ospeed, define this.
 */
#undef NEED_OSPEED

/*
 * Define SIGVOID if your signal handlers return void.  On older
 * systems, signal returns int, but on newer ones, it returns void.
 */
#undef SIGVOID

/*
 * Define USESIGSET if you have sigset for BSD 4.1 reliable signals.
 */
#undef USESIGSET

/*
 * If your system has getutent(), pututline(), etc. to write to the
 * utmp file, define GETUTENT.
 */
#undef GETUTENT

/*
 * Define UTHOST if the utmp file has a host field.
 */
#undef UTHOST

/*
 * Define if you have the utempter utmp helper program
 */
#undef HAVE_UTEMPTER

/*
 * Define if your utmpx has ut_exit struct
 */
#undef HAVE_UT_EXIT

/*
 * If your system has the calls setreuid() and setregid(),
 * define HAVE_SETREUID. Otherwise screen will use a forked process to
 * safely create output files without retaining any special privileges.
 */
#undef HAVE_SETRESUID
#undef HAVE_SETREUID

/*
 * execvpe is now defined in some systems.
 */
#undef HAVE_EXECVPE

/*
 * If your system has the new format /etc/ttys (like 4.3 BSD) and the
 * getttyent(3) library functions, define GETTTYENT.
 */
#undef GETTTYENT

/*
 * If your system has vsprintf() and requires the use of the macros in
 * "varargs.h" to use functions with variable arguments,
 * define USEVARARGS.
 */
#undef USEVARARGS

/*
 * define HAVE_NL_LANGINFO if your system has the nl_langinfo() call
 * and <langinfo.h> defines CODESET.
 */
#undef HAVE_NL_LANGINFO

/*
 * define PTYRANGE0 and or PTYRANGE1 if you want to adapt screen
 * to unusual environments. E.g. For SunOs the defaults are "qpr" and
 * "0123456789abcdef". For SunOs 4.1.2
 * #define PTYRANGE0 "pqrstuvwxyzPQRST"
 * is recommended by Dan Jacobson.
 */
#undef PTYRANGE0
#undef PTYRANGE1

