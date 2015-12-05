// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GIOMM_FILEATTRIBUTEINFO_H
#define _GIOMM_FILEATTRIBUTEINFO_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <string>
#include <gio/gio.h> //TODO: avoid this include
#include <glibmm/object.h>


namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_INVALID
 * Indicates an invalid or uninitalized type.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_STRING
 * A null terminated UTF8 string.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_BYTE_STRING
 * A zero terminated string of non-zero bytes.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_BOOLEAN
 * A boolean value.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_UINT32
 * An unsigned 4-byte/32-bit integer.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_INT32
 * A signed 4-byte/32-bit integer.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_UINT64
 * An unsigned 8-byte/64-bit integer.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_INT64
 * A signed 8-byte/64-bit integer.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_OBJECT
 * A Object.
 * 
 *  @var FileAttributeType FILE_ATTRIBUTE_TYPE_STRINGV
 * A <tt>0</tt> terminated char **. @newin{2,22}
 * 
 *  @enum FileAttributeType
 * 
 * The data types for file attributes.
 *
 * @ingroup giommEnums
 */
enum FileAttributeType
{
  FILE_ATTRIBUTE_TYPE_INVALID,
  FILE_ATTRIBUTE_TYPE_STRING,
  FILE_ATTRIBUTE_TYPE_BYTE_STRING,
  FILE_ATTRIBUTE_TYPE_BOOLEAN,
  FILE_ATTRIBUTE_TYPE_UINT32,
  FILE_ATTRIBUTE_TYPE_INT32,
  FILE_ATTRIBUTE_TYPE_UINT64,
  FILE_ATTRIBUTE_TYPE_INT64,
  FILE_ATTRIBUTE_TYPE_OBJECT,
  FILE_ATTRIBUTE_TYPE_STRINGV
};

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::FileAttributeType> : public Glib::Value_Enum<Gio::FileAttributeType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{

/** 
 *  @var FileAttributeInfoFlags FILE_ATTRIBUTE_INFO_NONE
 * No flags set.
 * 
 *  @var FileAttributeInfoFlags FILE_ATTRIBUTE_INFO_COPY_WITH_FILE
 * Copy the attribute values when the file is copied.
 * 
 *  @var FileAttributeInfoFlags FILE_ATTRIBUTE_INFO_COPY_WHEN_MOVED
 * Copy the attribute values when the file is moved.
 * 
 *  @enum FileAttributeInfoFlags
 * 
 * Flags specifying the behaviour of an attribute.
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%FileAttributeInfoFlags operator|(FileAttributeInfoFlags, FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags operator&(FileAttributeInfoFlags, FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags operator^(FileAttributeInfoFlags, FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags operator~(FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags& operator|=(FileAttributeInfoFlags&, FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags& operator&=(FileAttributeInfoFlags&, FileAttributeInfoFlags)</tt><br>
 * <tt>%FileAttributeInfoFlags& operator^=(FileAttributeInfoFlags&, FileAttributeInfoFlags)</tt><br>
 */
enum FileAttributeInfoFlags
{
  FILE_ATTRIBUTE_INFO_NONE = 0x0,
  FILE_ATTRIBUTE_INFO_COPY_WITH_FILE = (1 << 0),
  FILE_ATTRIBUTE_INFO_COPY_WHEN_MOVED = (1 << 1)
};

/** @ingroup giommEnums */
inline FileAttributeInfoFlags operator|(FileAttributeInfoFlags lhs, FileAttributeInfoFlags rhs)
  { return static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags operator&(FileAttributeInfoFlags lhs, FileAttributeInfoFlags rhs)
  { return static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags operator^(FileAttributeInfoFlags lhs, FileAttributeInfoFlags rhs)
  { return static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags operator~(FileAttributeInfoFlags flags)
  { return static_cast<FileAttributeInfoFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags& operator|=(FileAttributeInfoFlags& lhs, FileAttributeInfoFlags rhs)
  { return (lhs = static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags& operator&=(FileAttributeInfoFlags& lhs, FileAttributeInfoFlags rhs)
  { return (lhs = static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline FileAttributeInfoFlags& operator^=(FileAttributeInfoFlags& lhs, FileAttributeInfoFlags rhs)
  { return (lhs = static_cast<FileAttributeInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::FileAttributeInfoFlags> : public Glib::Value_Flags<Gio::FileAttributeInfoFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{

/** 
 *  @var FileAttributeStatus FILE_ATTRIBUTE_STATUS_UNSET
 * Attribute value is unset (empty).
 * 
 *  @var FileAttributeStatus FILE_ATTRIBUTE_STATUS_SET
 * Attribute value is set.
 * 
 *  @var FileAttributeStatus FILE_ATTRIBUTE_STATUS_ERROR_SETTING
 * Indicates an error in setting the value.
 * 
 *  @enum FileAttributeStatus
 * 
 * Used by g_file_set_attributes_from_info() when setting file attributes.
 *
 * @ingroup giommEnums
 */
enum FileAttributeStatus
{
  FILE_ATTRIBUTE_STATUS_UNSET,
  FILE_ATTRIBUTE_STATUS_SET,
  FILE_ATTRIBUTE_STATUS_ERROR_SETTING
};

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::FileAttributeStatus> : public Glib::Value_Enum<Gio::FileAttributeStatus>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{


/** Information about a specific attribute - see FileAttributeInfoList.
 *
 * @newin{2,16}
 */
class FileAttributeInfo
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FileAttributeInfo CppObjectType;
  typedef GFileAttributeInfo BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  explicit FileAttributeInfo(const GFileAttributeInfo* ginfo);

  FileAttributeInfo(const FileAttributeInfo& other);
  FileAttributeInfo& operator=(const FileAttributeInfo& other);

  FileAttributeInfo(FileAttributeInfo&& other) noexcept;
  FileAttributeInfo& operator=(FileAttributeInfo&& other) noexcept;

  ~FileAttributeInfo();

  std::string get_name() const;
  FileAttributeType get_type() const;
  FileAttributeInfoFlags get_flags() const;

protected:
  std::string m_name;
  FileAttributeType m_type;
  FileAttributeInfoFlags m_flags;


};

} // namespace Gio


#endif /* _GIOMM_FILEATTRIBUTEINFO_H */

