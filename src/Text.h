#ifndef PT_TEXT_H
#define PT_TEXT_H

#include <photon/PtText.h>

#include <string>

#include "./Label.h"


namespace PhWidgets
{
		
	class Text:
		public Label
	{
	public:

		struct ThisArgs
		{												
			struct ArgComplex
			{
				enum eArgComplex
				{
					text_substring = Pt_ARG_TEXT_SUBSTRING
				};
			};

		};
		
		struct ArgComplex:
			public ThisArgs::ArgComplex
		{
		};

		
		struct Arguments:
			public ArgComplex,
			public Label::Arguments
		{
		};
		
	protected:
		virtual void check();

						
	public:
		Text(int abn);
		Text(PtWidget_t *wdg);
	};
	
	INIT_WIDGET_RESOURCE1(Text::ThisArgs::ArgComplex::eArgComplex, PtTextControl_t, Struct);
}


#endif
