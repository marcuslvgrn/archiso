// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GIOMM_NOTIFICATION_H
#define _GIOMM_NOTIFICATION_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <glibmm/object.h>
#include <glibmm/ustring.h>
#include <glibmm/variant.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GNotification GNotification;
typedef struct _GNotificationClass GNotificationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class Notification_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class Icon;

/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var NotificationPriority NOTIFICATION_PRIORITY_LOW
 * For notifications that do not require
 * immediate attention - typically used for contextual background
 * information, such as contact birthdays or local weather.
 * 
 *  @var NotificationPriority NOTIFICATION_PRIORITY_NORMAL
 * The default priority, to be used for the
 * majority of notifications (for example email messages, software updates,
 * completed download/sync operations).
 * 
 *  @var NotificationPriority NOTIFICATION_PRIORITY_HIGH
 * For events that require more attention,
 * usually because responses are time-sensitive (for example chat and SMS
 * messages or alarms).
 * 
 *  @var NotificationPriority NOTIFICATION_PRIORITY_URGENT
 * For urgent notifications, or notifications
 * that require a response in a short space of time (for example phone calls
 * or emergency warnings).
 * 
 *  @enum NotificationPriority
 * 
 * Priority levels for Notifications.
 * 
 * @newin{2,44}
 *
 * @ingroup giommEnums
 */
enum NotificationPriority
{
  NOTIFICATION_PRIORITY_NORMAL,
  NOTIFICATION_PRIORITY_LOW,
  NOTIFICATION_PRIORITY_HIGH,
  NOTIFICATION_PRIORITY_URGENT
};

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::NotificationPriority> : public Glib::Value_Enum<Gio::NotificationPriority>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{


/** User Notifications (pop up messages).
 *
 * Gio::Notification is a mechanism for creating a notification to be shown
 * to the user -- typically as a pop-up notification presented by the
 * desktop environment shell.
 *
 * The key difference between Notification and other similar APIs is
 * that, if supported by the desktop environment, notifications sent
 * with Notification will persist after the application has exited,
 * and even across system reboots.
 *
 * Since the user may click on a notification while the application is
 * not running, applications using Notification should be able to be
 * started as a D-Bus service, using Gio::Application.
 *
 * User interaction with a notification (either the default action, or
 * buttons) must be associated with actions on the application (ie:
 * "app." actions).  It is not possible to route user interaction
 * through the notification itself, because the object will not exist if
 * the application is autostarted as a result of a notification being
 * clicked.
 *
 * A notification can be sent with Gio::Application::send_notification().
 *
 * @newin{2,40}
 */

class Notification : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Notification CppObjectType;
  typedef Notification_Class CppClassType;
  typedef GNotification BaseObjectType;
  typedef GNotificationClass BaseClassType;

  // noncopyable
  Notification(const Notification&) = delete;
  Notification& operator=(const Notification&) = delete;

private:  friend class Notification_Class;
  static CppClassType notification_class_;

protected:
  explicit Notification(const Glib::ConstructParams& construct_params);
  explicit Notification(GNotification* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Notification(Notification&& src) noexcept;
  Notification& operator=(Notification&& src) noexcept;

  virtual ~Notification() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GNotification*       gobj()       { return reinterpret_cast<GNotification*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GNotification* gobj() const { return reinterpret_cast<GNotification*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GNotification* gobj_copy();

private:


protected:
  // Can't use _WRAP_CTOR. GNotification has no properties, but it must have a title.
  explicit Notification(const Glib::ustring& title);
  

public:
  
  /** Creates a new Notification with @a title as its title.
   * 
   * After populating @a notification with more details, it can be sent to
   * the desktop shell with g_application_send_notification(). Changing
   * any properties after this call will not have any effect until
   * resending @a notification.
   * 
   * @newin{2,40}
   * 
   * @param title The title of the notification.
   * @return A new Notification instance.
   */

  
  static Glib::RefPtr<Notification> create(const Glib::ustring& title);


  /** Sets the title of @a notification to @a title.
   * 
   * @newin{2,40}
   * 
   * @param title The new title for @a notification.
   */
  void set_title(const Glib::ustring& title);
  
  /** Sets the body of @a notification to @a body.
   * 
   * @newin{2,40}
   * 
   * @param body The new body for @a notification, or <tt>0</tt>.
   */
  void set_body(const Glib::ustring& body);
  
  /** Sets the icon of @a notification to @a icon.
   * 
   * @newin{2,40}
   * 
   * @param icon The icon to be shown in @a notification, as a Icon.
   */
  void set_icon(const Glib::RefPtr<Icon>& icon);
  
#ifndef GIOMM_DISABLE_DEPRECATED

  /** Deprecated in favor of g_notification_set_priority().
   * 
   * @newin{2,40}
   * 
   * @deprecated Use set_priority() instead.
   * 
   * @param urgent <tt>true</tt> if @a notification is urgent.
   */
  void set_urgent(bool urgent =  true);
#endif // GIOMM_DISABLE_DEPRECATED


  /** Sets the priority of @a notification to @a priority. See
   * NotificationPriority for possible values.
   * 
   * @newin{2,44}
   * 
   * @param priority A NotificationPriority.
   */
  void set_priority(NotificationPriority priority =  NOTIFICATION_PRIORITY_NORMAL);

  
  /** Adds a button to @a notification that activates the action in
   *  @a detailed_action when clicked. That action must be an
   * application-wide action (starting with "app."). If @a detailed_action
   * contains a target, the action will be activated with that target as
   * its parameter.
   * 
   * See g_action_parse_detailed_name() for a description of the format
   * for @a detailed_action.
   * 
   * @newin{2,40}
   * 
   * @param label Label of the button.
   * @param detailed_action A detailed action name.
   */
  void add_button(const Glib::ustring& label, const Glib::ustring& detailed_action);

  /** Adds a button that activates @a action when clicked.
   * @a action must be an application-wide action (it must start with "app.").
   * @a action will be activated with @a target as its parameter.
   *
   * @newin{2,40}
   *
   * @param label Label of the button.
   * @param action An action name.
   * @param target @a action's parameter.
   */
  template <typename T_Value>
  void add_button(const Glib::ustring& label, const Glib::ustring& action, const T_Value& target);

  
  /** Adds a button to @a notification that activates @a action when clicked.
   *  @a action must be an application-wide action (it must start with "app.").
   * 
   * If @a target is non-<tt>0</tt>, @a action will be activated with @a target as
   * its parameter.
   * 
   * @newin{2,40}
   * 
   * @param label Label of the button.
   * @param action An action name.
   * @param target A Variant to use as @a action's parameter, or <tt>0</tt>.
   */
  void add_button_variant(const Glib::ustring& label, const Glib::ustring& action, const Glib::VariantBase& target);

  
  /** Sets the default action of @a notification to @a detailed_action. This
   * action is activated when the notification is clicked on.
   * 
   * The action in @a detailed_action must be an application-wide action (it
   * must start with "app."). If @a detailed_action contains a target, the
   * given action will be activated with that target as its parameter.
   * See g_action_parse_detailed_name() for a description of the format
   * for @a detailed_action.
   * 
   * When no default action is set, the application that the notification
   * was sent on is activated.
   * 
   * @newin{2,40}
   * 
   * @param detailed_action A detailed action name.
   */
  void set_default_action(const Glib::ustring& detailed_action);

  /** Sets the default action to @a action.
   * This action is activated when the notification is clicked on. It must be an
   * application-wide action (start with "app.").
   * @a action will be activated with @a target as its parameter.
   *
   * When no default action is set, the application that the notification
   * was sent on is activated.
   *
   * @newin{2,40}
   *
   * @param action An action name.
   * @param target @a action's parameter.
   */
  template <typename T_Value>
  void set_default_action(const Glib::ustring& action, const T_Value& target);

  
  /** Sets the default action of @a notification to @a action. This action is
   * activated when the notification is clicked on. It must be an
   * application-wide action (start with "app.").
   * 
   * If @a target is non-<tt>0</tt>, @a action will be activated with @a target as
   * its parameter.
   * 
   * When no default action is set, the application that the notification
   * was sent on is activated.
   * 
   * @newin{2,40}
   * 
   * @param action An action name.
   * @param target A Variant to use as @a action's parameter, or <tt>0</tt>.
   */
  void set_default_action_variant(const Glib::ustring& action, const Glib::VariantBase& target);

  // Ignore functions with variable-length parameter lists.
  

  // There are no properties, signals, vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

template <typename T_Value>
void Notification::add_button(const Glib::ustring& label, const Glib::ustring& action, const T_Value& target)
{
  typedef Glib::Variant<T_Value> type_glib_variant;

  add_button_variant(label, action, type_glib_variant::create(target));
}

template <typename T_Value>
void Notification::set_default_action(const Glib::ustring& action, const T_Value& target)
{
  typedef Glib::Variant<T_Value> type_glib_variant;

  set_default_action_variant(action, type_glib_variant::create(target));
}

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Notification
   */
  Glib::RefPtr<Gio::Notification> wrap(GNotification* object, bool take_copy = false);
}


#endif /* _GIOMM_NOTIFICATION_H */
