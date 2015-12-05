// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GIOMM_SETTINGSSCHEMAKEY_H
#define _GIOMM_SETTINGSSCHEMAKEY_H

#include <giommconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The giomm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <glibmm/variant.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchemaKey GSettingsSchemaKey;
#endif

namespace Gio
{

//TODO: Add some class documentation, though there is none in the C docs.

/** See SettingsSchema.
 *
 * @newin{2,32}
 */
class SettingsSchemaKey final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SettingsSchemaKey CppObjectType;
  typedef GSettingsSchemaKey BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  GSettingsSchemaKey*       gobj();

  ///Provides access to the underlying C instance.
  const GSettingsSchemaKey* gobj() const;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GSettingsSchemaKey* gobj_copy() const;

  SettingsSchemaKey() = delete;

  // noncopyable
  SettingsSchemaKey(const SettingsSchemaKey&) = delete;
  SettingsSchemaKey& operator=(const SettingsSchemaKey&) = delete;

protected:
  // Do not derive this.  Gio::SettingsSchemaKey can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


protected:
  

  //Ignore internal GSettingsSchemaKey functions.
  

public:
  //TODO: _WRAP_METHOD(const GVariantType *    g_settings_schema_key_get_value_type           (), g_settings_schema_key_get_value_type)
  //_WRAP_METHOD(GVariant *              g_settings_schema_key_get_default_value        (), g_settings_schema_key_get_default_value)
  //_WRAP_METHOD(GVariant *              g_settings_schema_key_get_range                (), g_settings_schema_key_get_range)
  //TODO: _WRAP_METHOD(bool range_check(GVariant               *value), g_settings_schema_key_range_check)

  
  /** Gets the name of @a key.
   * 
   * @newin{2,44}
   * 
   * @return The name of @a key.
   */
  Glib::ustring get_name() const;
  
  /** Gets the summary for @a key.
   * 
   * If no summary has been provided in the schema for @a key, returns
   * <tt>0</tt>.
   * 
   * The summary is a short description of the purpose of the key; usually
   * one short sentence.  Summaries can be translated and the value
   * returned from this function is is the current locale.
   * 
   * This function is slow.  The summary and description information for
   * the schemas is not stored in the compiled schema database so this
   * function has to parse all of the source XML files in the schema
   * directory.
   * 
   * @newin{2,34}
   * 
   * @return The summary for @a key, or <tt>0</tt>.
   */
  Glib::ustring get_summary() const;
  
  /** Gets the description for @a key.
   * 
   * If no description has been provided in the schema for @a key, returns
   * <tt>0</tt>.
   * 
   * The description can be one sentence to several paragraphs in length.
   * Paragraphs are delimited with a double newline.  Descriptions can be
   * translated and the value returned from this function is is the
   * current locale.
   * 
   * This function is slow.  The summary and description information for
   * the schemas is not stored in the compiled schema database so this
   * function has to parse all of the source XML files in the schema
   * directory.
   * 
   * @newin{2,34}
   * 
   * @return The description for @a key, or <tt>0</tt>.
   */
  Glib::ustring get_description() const;


};

} // namespace Gio


namespace Glib
{

  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SettingsSchemaKey
   */
  Glib::RefPtr<Gio::SettingsSchemaKey> wrap(GSettingsSchemaKey* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_SETTINGSSCHEMAKEY_H */

