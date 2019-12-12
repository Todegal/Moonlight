#pragma once

#include <sstream>

namespace ML
{
	enum EventType
	{
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		NumEvents
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

#define GET_EVENTS(disc) \
	disc("WindowClose", EventType::WindowClose, WindowCloseEvent) \
	disc("WindowResize", EventType::WindowResize, WindowResizeEvent) \
	disc("WindowFocus", EventType::WindowFocus, WindowFocusEvent) \
	disc("WindowLostFocus", EventType::WindowLostFocus, WindowLostFocusEvent) \
	disc("WindowMoved", EventType::WindowMoved, WindowMovedEvent) \
	disc("AppTick", EventType::AppTick, AppTickEvent) \
	disc("AppUpdate", EventType::AppUpdate, AppUpdateEvent) \
	disc("AppRender", EventType::AppRender, AppRenderEvent) \
	disc("KeyPressed", EventType::KeyPressed, KeyPressedEvent) \
	disc("KeyReleased", EventType::KeyReleased, KeyReleasedEvent) \
	disc("KeyTyped", EventType::KeyTyped, KeyTypedEvent) \
	disc("MouseButtonPressed", EventType::MouseButtonPressed, MouseButtonPressedEvent) \
	disc("MouseButtonReleased", EventType::MouseButtonReleased, MouseButtonReleasedEvent) \
	disc("MouseMoved", EventType::MouseMoved, MouseMovedEvent) \
	disc("MouseScrolled", EventType::MouseScrolled, MouseScrolledEvent) \

	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}