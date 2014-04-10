/* QLeapGuiExport.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Sat Dec 22 01:06:42 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Feb 21 11:40:26 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 4
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef QLEAPGUI_EXPORT_H
#define QLEAPGUI_EXPORT_H

#ifdef QLEAPGUI_STATIC_DEFINE
#  define QLEAPGUI_EXPORT
#  define QLEAPGUI_NO_EXPORT
#else
#  ifndef QLEAPGUI_EXPORT
#    ifdef QLeapGui_EXPORTS
// http://gcc.gnu.org/wiki/Visibility
#      ifdef __GNUC__
#        define QLEAPGUI_EXPORT __attribute__((visibility("default")))
#      else
#        define QLEAPGUI_EXPORT __declspec(dllexport)
#      endif
#    else
#      ifdef __GNUC__
#        define QLEAPGUI_EXPORT __attribute__((visibility("default")))
#      else
#        define QLEAPGUI_EXPORT __declspec(dllimport)
#      endif
#    endif
#  endif

#  ifndef QLEAPGUI_NO_EXPORT
#    define QLEAPGUI_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef QLEAPGUI_DEPRECATED
#  define QLEAPGUI_DEPRECATED __attribute__ ((__deprecated__))
#  define QLEAPGUI_DEPRECATED_EXPORT QLEAPGUI_EXPORT __attribute__ ((__deprecated__))
#  define QLEAPGUI_DEPRECATED_NO_EXPORT QLEAPGUI_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define QLEAPGUI_NO_DEPRECATED
#endif

#endif
