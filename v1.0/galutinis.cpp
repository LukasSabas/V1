#include "galutinis.h"
#include "studentas.h"
void galutinis(struct studentas& s) {
	s.galv = s.vid * 0.4 + s.egz * 0.6;
	s.galm = s.med * 0.4 + s.egz * 0.6;
}