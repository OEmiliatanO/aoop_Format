#ifndef __FORM_H__
#define __FORM_H__

#include <ios>
#include <iomanip>
#include <ostream>

using std::ostream;
using std::ios_base;

class Form
{
private:
	ios_base::fmtflags fmt;
	uint32_t prec;
	double val;
	friend ostream& operator<<(ostream& o, const Form& form);
public:
	
	explicit Form(uint32_t prec_ = 6): prec(prec_), val(0) {}
	constexpr Form(const Form& f): prec(f.prec), val(f.val), fmt(f.fmt) {}
	Form& operator=(const Form& f)
	{
		if (this == &f) return *this;
		fmt = f.fmt;
		val = f.val;
		prec = f.prec;
		return *this;
	}
	
	Form& scientific()
	{
		fmt = ios_base::scientific;
		return *this;
	}
	Form& fixed()
	{
		fmt = ios_base::fixed;
		return *this;
	}

	Form& precision(const uint32_t& prec_)
	{
		prec = prec_;
		return *this;
	}

	Form& operator()(const double& v)
	{
		val = v;
		return *this;
	}
};

#endif
