#include "Form.h"
#include <sstream>
#include <ostream>
#include <ios>

using std::ostream;
using std::ostringstream;
using std::ios_base;

ostream& operator<<(ostream& o, const Form& f)
{
	ostringstream obuf;
	obuf.setf(f.fmt, ios_base::floatfield);
	obuf.precision(f.prec);
	obuf << f.val;
	return o << obuf.str();
}
