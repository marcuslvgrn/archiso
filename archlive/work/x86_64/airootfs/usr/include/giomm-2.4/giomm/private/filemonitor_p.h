// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GIOMM_FILEMONITOR_P_H
#define _GIOMM_FILEMONITOR_P_H


#include <glibmm/private/object_p.h>
#include <gio/gio.h>

#include <glibmm/class.h>

namespace Gio
{

class FileMonitor_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FileMonitor CppObjectType;
  typedef GFileMonitor BaseObjectType;
  typedef GFileMonitorClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class FileMonitor;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void changed_callback(GFileMonitor* self, GFile* p0, GFile* p1, GFileMonitorEvent p2);

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_FILEMONITOR_P_H */
