/*
 * Wolfenstein: Enemy Territory GPL Source Code
 * Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.
 *
 * ET: Legacy
 * Copyright (C) 2012 Jan Simek <mail@etlegacy.com>
 *
 * This file is part of ET: Legacy - http://www.etlegacy.com
 *
 * ET: Legacy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ET: Legacy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ET: Legacy. If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, Wolfenstein: Enemy Territory GPL Source Code is also
 * subject to certain additional terms. You should have received a copy
 * of these additional terms immediately following the terms and conditions
 * of the GNU General Public License which accompanied the source code.
 * If not, please request a copy in writing from id Software at the address below.
 *
 * id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
 *
 * @file l_struct.h
 * @brief structure reading / writing
 */

#define MAX_STRINGFIELD             80
//field types
#define FT_CHAR                     1           // char
#define FT_INT                          2           // int
#define FT_FLOAT                        3           // float
#define FT_STRING                       4           // char [MAX_STRINGFIELD]
#define FT_STRUCT                       6           // struct (sub structure)
//type only mask
#define FT_TYPE                     0x00FF  // only type, clear subtype
//sub types
#define FT_ARRAY                        0x0100  // array of type
#define FT_BOUNDED                  0x0200  // bounded value
#define FT_UNSIGNED                 0x0400

//structure field definition
typedef struct fielddef_s
{
	char *name;                                     //name of the field
	int offset;                                     //offset in the structure
	int type;                                       //type of the field
	//type specific fields
	int maxarray;                                   //maximum array size
	float floatmin, floatmax;                   //float min and max
	struct structdef_s *substruct;          //sub structure
} fielddef_t;

//structure definition
typedef struct structdef_s
{
	int size;
	fielddef_t *fields;
} structdef_t;

//read a structure from a script
int ReadStructure(source_t *source, structdef_t *def, char *structure);
//write a structure to a file
int WriteStructure(FILE *fp, structdef_t *def, char *structure);
//writes indents
int WriteIndent(FILE *fp, int indent);
//writes a float without traling zeros
int WriteFloat(FILE *fp, float value);
