#include "cnf.h"

int main()
{
	CNF *sat=new CNF;
	sat->init();
	sat->solver();
}