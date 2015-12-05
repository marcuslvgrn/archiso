// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GIOMM_DBUSPROXY_P_H
#define _GIOMM_DBUSPROXY_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gio
{

namespace DBus
{

class Proxy_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Proxy CppObjectType;
  typedef GDBusProxy BaseObjectType;
  typedef GDBusProxyClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class Proxy;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void g_properties_changed_callback(GDBusProxy* self, GVariant* p0, const gchar*const* p1);
  static void g_signal_callback(GDBusProxy* self, const gchar* p0, const gchar* p1, GVariant* p2);

  //Callbacks (virtual functions):
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSPROXY_P_H */

