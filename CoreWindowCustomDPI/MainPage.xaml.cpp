//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "CoreWindowHelpers.h"

using namespace CoreWindowCustomDPI;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Graphics::Display;

using namespace InternalsRT::Core::Windowing;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void MainPage::StackPanel_Loaded(Object^ sender, RoutedEventArgs^ e)
{
	DisplayInformation^ info = DisplayInformation::GetForCurrentView();
	DpiSlider->Value = info->RawPixelsPerViewPixel * 100;

	DpiSlider->ValueChanged += ref new RangeBaseValueChangedEventHandler(this, &CoreWindowCustomDPI::MainPage::OnValueChanged);
}


void CoreWindowCustomDPI::MainPage::OnValueChanged(Object^ sender, RangeBaseValueChangedEventArgs^ e)
{
	CoreWindowHelpers::OverrideDpiForCurrentThread((float)e->NewValue * 96.0f / 100.0f);
}
