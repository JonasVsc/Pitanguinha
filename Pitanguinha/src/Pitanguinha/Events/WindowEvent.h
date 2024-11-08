#pragma once

#include "Event.h"


class WindowCloseEvent : public Event
{
public:

	WindowCloseEvent() {}

	EventType GetEventType() const override { return EventType::WindowClose;  }

	static constexpr EventType GetStaticType() { return EventType::WindowClose; }
}; 