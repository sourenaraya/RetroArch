/* RetroArch - A frontend for libretro.
 * Copyright (C) 2011-2015 - Daniel De Matteis
 *
 * RetroArch is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Found-
 * ation, either version 3 of the License, or (at your option) any later version.
 *
 * RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 * * You should have received a copy of the GNU General Public License along with RetroArch.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "../frontend_driver.h"

#include <stdint.h>
#include <boolean.h>
#include <stddef.h>
#include <string.h>

#include "../general.h"

static void frontend_win32_get_os(char *name, size_t sizeof_name, int *major, int *minor)
{
	DWORD version = GetVersion();

	*major   = (DWORD)(LOBYTE(LOWORD(version)));
	*minor   = (DWORD)(HIBYTE(LOWORD(version)));
}

static void frontend_win32_environment_get(int *argc, char *argv[],
	void *args, void *params_data)
{
}

const frontend_ctx_driver_t frontend_ctx_win32 = {
   frontend_win32_environment_get, /* environment_get */
   NULL,                           /* init */
   NULL,                           /* deinit */
   NULL,                           /* exitspawn */
   NULL,                           /* process_args */
   NULL,                           /* exec */
   NULL,                           /* set_fork */
   NULL,                           /* shutdown */
   NULL,                           /* get_name */
   frontend_win32_get_os,          /* get_os */
   NULL,                           /* get_rating */
   NULL,                           /* load_content */
   "win32",
};
