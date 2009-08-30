 /*
 				astrefcat.h

*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	Part of:	SCAMP
*
*	Author:		E.BERTIN (IAP)
*
*	Contents:	Include file for refcat.c.
*
*	Last modify:	26/06/2009
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#ifndef _FIELD_H_
#include "field.h"
#endif

#ifndef _SAMPLES_H_
#include "samples.h"
#endif

#ifndef _ASTREFCAT_H_
#define _ASTREFCAT_H_

/*----------------------------- Internal constants --------------------------*/
#define		MAX_SERVER	16
#define		MAX_BAND	16	/* Maximum number of bands */
#define		DENIS3_POSERR	(0.20*ARCSEC/DEG)
#define		SDSSR3_POSERR	(0.10*ARCSEC/DEG)
#define		USNOA1_POSERR	(0.25*ARCSEC/DEG)
#define		USNOA2_POSERR	(0.25*ARCSEC/DEG)
#define		USNOB1_POSERR	(0.25*ARCSEC/DEG)	/* if not given */
#define		USNOA1_BMAGERR	0.40
#define		USNOA2_BMAGERR	0.40
#define		USNOB1_BMAGERR	0.40
#define         NOMAD1_MAGERR   0.30

#define		ASTREF_ASSOCRADIUS	(0.2*ARCSEC/DEG)

/*--------------------------------- typedefs --------------------------------*/
typedef enum {ASTREFCAT_NONE, ASTREFCAT_FILE,
		ASTREFCAT_USNOA1, ASTREFCAT_USNOA2, ASTREFCAT_USNOB1,
		ASTREFCAT_GSC1, ASTREFCAT_GSC2,
		ASTREFCAT_2MASS, ASTREFCAT_DENIS3,
		ASTREFCAT_UCAC1, ASTREFCAT_UCAC2,
		ASTREFCAT_SDSSR3, ASTREFCAT_SDSSR5, ASTREFCAT_SDSSR6,
		ASTREFCAT_NOMAD1}
			astrefenum;

typedef struct
  {
  char		name[16];		/* Catalog name */
  int		nband;			/* Number of available bands */
  int		defband;		/* Default band */
  char		bandnames[MAX_BAND][32];/* Names of available bands */
  int		band;			/* Chosen band */
  char		*bandname;		/* Name of chosen band */
  }	astrefstruct;

extern astrefstruct   astrefcat[];

/*------------------------------- functions ---------------------------------*/

extern fieldstruct	*get_astreffield(astrefenum refcat, double *wcspos,
                                int lng, int lat, int naxis, double maxradius),
			*load_astreffield(char *filename, double *wcspos,
				int lng, int lat,
				int naxis, double maxradius, int band);

extern setstruct	*read_astrefsamples(setstruct *set, tabstruct *tab,
				char *rfilename,
				double *wcspos,
				int lng, int lat,
				int naxis, double maxradius, int band);

extern void		save_astreffield(char *filename, fieldstruct *reffield);

#endif