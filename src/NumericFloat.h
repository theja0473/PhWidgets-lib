#ifndef PT_NUMERIC_FLOAT_H
#define PT_NUMERIC_FLOAT_H

#include <photon/PtNumericFloat.h>

#include "./Numeric.h"


namespace PhWidgets
{
		
	class NumericFloat:
		public Numeric
	{
	public:

		struct ThisArgs
		{												
			struct ArgInt
			{				
				enum eArgInt
				{
					numeric_precision = Pt_ARG_NUMERIC_PRECISION
				};
			};
			
			struct ArgDoubleP
			{
				enum eArgDoubleP
				{
					numeric_increment = Pt_ARG_NUMERIC_INCREMENT,
					numeric_max = Pt_ARG_NUMERIC_MAX,
					numeric_min = Pt_ARG_NUMERIC_MIN,
					numeric_value = Pt_ARG_NUMERIC_VALUE
				};
			};


		};
		
		struct ArgInt:
			public ThisArgs::ArgInt
		{
		};
		
		struct ArgDoubleP:
			public ThisArgs::ArgDoubleP
		{
		};


			
		struct Arguments:
			public ArgInt,
			public ArgDoubleP,
			public Numeric::Arguments
		{
		};


	protected:
		virtual void check();
		
		double getValue() const;
		void setValue(double val);
		
		double getMaxValue() const;
		void setMaxValue(double val);
		
		double getMinValue() const;
		void setMinValue(double val);
						
	public:
		NumericFloat(int abn);
		NumericFloat(PtWidget_t *wdg);
		
		NumericFloat(const NumericFloat&);
		
		property<double>::bind<NumericFloat, &NumericFloat::getValue, &NumericFloat::setValue> Value;
		property<double>::bind<NumericFloat, &NumericFloat::getMaxValue, &NumericFloat::setMaxValue> MaxValue;
		property<double>::bind<NumericFloat, &NumericFloat::getMinValue, &NumericFloat::setMinValue> MinValue;
		
	};
	
	INIT_WIDGET_RESOURCE1(NumericFloat::ThisArgs::ArgDoubleP::eArgDoubleP, double*, Struct);
	
	INIT_WIDGET_RESOURCE1(NumericFloat::ThisArgs::ArgInt::eArgInt, int, Scalar);

}


#endif
