/*
    SDL_net:  An example cross-platform network library for use with SDL
    Copyright (C) 1997, 1998, 1999, 2000, 2001  Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org
*/

/* $Id: SDLnetsys.h,v 1.6 2003/01/21 02:56:35 slouken Exp $ */

/* Include normal system headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef macintosh
#ifndef USE_GUSI_SOCKETS
#define MACOS_OPENTRANSPORT
//#error Open Transport driver is broken
#endif
#endif /* macintosh */

/* Include system network headers */
#ifdef MACOS_OPENTRANSPORT
#include <OpenTransport.h>
#include <OpenTptInternet.h>
#else
#if defined(_XBOX)
#define __USE_W32_SOCKETS
#include <xtl.h>
#include <winsockx.h>
#elif defined(__WIN32__) || defined(WIN32)
#define __USE_W32_SOCKETS
#include <windows.h>
#else /* UNIX */
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#ifndef __BEOS__
#include <arpa/inet.h>
#endif
#ifdef linux /* FIXME: what other platforms have this? */
#include <netinet/tcp.h>
#endif
#include <netdb.h>
#include <sys/socket.h>
#endif /* WIN32 */
#endif /* Open Transport */

/* System-dependent definitions */
#ifdef MACOS_OPENTRANSPORT
//#define closesocket	OTCloseProvider
#define closesocket OTSndOrderlyDisconnect
#define SOCKET		EndpointRef
#define INVALID_SOCKET	kOTInvalidEndpointRef
#else
#ifndef __USE_W32_SOCKETS
#define closesocket	close
#define SOCKET	int
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
#endif /* __USE_W32_SOCKETS */
#endif /* Open Transport */

