// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "ICompassView.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include "AndroidNativeState.h"

#include <string>
#include <memory>

namespace ExampleApp
{
    namespace Compass
    {
        namespace View
        {
            class CompassView : public ICompassView, private Eegeo::NonCopyable
            {
            private:
                Eegeo::Helpers::CallbackCollection0 m_callbacks;
                const std::shared_ptr<AndroidNativeState> m_nativeState;

                jclass m_uiViewClass;
                jobject m_uiView;

                void CallVoidMethod(const std::string& methodName);
            public:
                CompassView(const std::shared_ptr<AndroidNativeState>& nativeState);
                ~CompassView();

                void OnCycle();

                void ShowGpsDisabledView();

                void ShowGpsFollowView();

                void ShowGpsCompassModeView();

                void NotifyGpsUnauthorized();

                void SetHeadingRadians(float heading);

                void SetOnScreenStateToIntermediateValue(float value);

                void SetFullyOnScreen();

                void SetFullyOffScreen();

                void InsertCycledCallback(Eegeo::Helpers::ICallback0& callback);

                void RemoveCycledCallback(Eegeo::Helpers::ICallback0& callback);
            };
        }
    }
}
