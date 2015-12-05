// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_COMBOBOX_H
#define _GTKMM_COMBOBOX_H


#include <glibmm.h>

/* $Id: combobox.hg,v 1.17 2006/09/19 20:08:42 murrayc Exp $ */

/* combobox.h
 * 
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/bin.h>
#include <gtkmm/celllayout.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/cellrenderer.h>
#include <gtkmm/treeview.h>
#include <gtkmm/enums.h> //For SensitivityType.


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkComboBox GtkComboBox;
typedef struct _GtkComboBoxClass GtkComboBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class ComboBox_Class; } // namespace Gtk
namespace Gtk
{

/** A widget used to choose from a list of items.
 *
 * A ComboBox is a widget that allows the user to choose from a list of valid choices. The ComboBox displays the 
 * selected choice. When activated, the ComboBox displays a popup which allows the user to make a new choice. The 
 * style in which the selected value is displayed, and the style of the popup is determined by the current theme. 
 * It may be similar to a OptionMenu, or similar to a Windows-style combo box.
 *
 * The ComboBox uses the model-view pattern; the list of valid choices is specified in the form of a tree model, 
 * and the display of the choices can be adapted to the data in the model by using cell renderers, as you would in 
 * a tree view. This is possible since ComboBox implements the CellLayout interface. The tree model holding the 
 * valid choices is not restricted to a flat list, it can be a real tree, and the popup will reflect the tree 
 * structure.
 *
 * The ComboBox widget looks like this with has_entry = false:
 * @image html combobox1.png
 *
 * The ComboBox widget looks like this with has_entry = true:
 * @image html comboboxentry1.png
 *
 * See also ComboBoxText, which is specialised for a single text column.
 *
 * @ingroup Widgets
 */

class ComboBox
: public Bin,
  public CellLayout
//TODO: Since GTK+ 2.6, this should now inherit also from CellEditable, but we can't add this base without breaking ABI.
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ComboBox CppObjectType;
  typedef ComboBox_Class CppClassType;
  typedef GtkComboBox BaseObjectType;
  typedef GtkComboBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~ComboBox();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class ComboBox_Class;
  static CppClassType combobox_class_;

  // noncopyable
  ComboBox(const ComboBox&);
  ComboBox& operator=(const ComboBox&);

protected:
  explicit ComboBox(const Glib::ConstructParams& construct_params);
  explicit ComboBox(GtkComboBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkComboBox*       gobj()       { return reinterpret_cast<GtkComboBox*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkComboBox* gobj() const { return reinterpret_cast<GtkComboBox*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_changed();


private:

  
public:
  ComboBox();
  
  /** Creates a new ComboBox with the model initialized to @a model.
   */
    explicit ComboBox(const Glib::RefPtr<TreeModel>& model);

   //See ComboBoxText for an equivalent of gtk_combo_box_new_text().

  /** Creates a new empty #GtkComboBox, optionally with an entry.
   * @param has_entry If this is true then this will have an Entry widget.
   *
   * newin{2,24}
   */
  explicit ComboBox(bool has_entry); //has_entry has a default value in gtkmm-3.0 but can't here because we already have a default constructor.
  
  /** Creates a new ComboBox with the model initialized to @a model.
   * @param model The model containing data to display in the ComboBox.
   * @param has_entry If this is true then this will have an Entry widget.
   *
   * newin{2,24}
   */
  explicit ComboBox(const Glib::RefPtr<TreeModel>& model, bool has_entry); //has_entry has a default value in gtkmm-3.0 but can't here because we already have a default constructor.
  
  
  /** Sets the wrap width of @a combo_box to be @a width. The wrap width is basically
   * the preferred number of columns when you want the popup to be layed out
   * in a table.
   * 
   * @newin{2,4}
   * @param width Preferred number of columns.
   */
  void set_wrap_width(int width);
  
  /** Returns the wrap width which is used to determine the number of columns 
   * for the popup menu. If the wrap width is larger than 1, the combo box 
   * is in table mode.
   * 
   * @newin{2,6}
   * @return The wrap width.
   */
  int get_wrap_width() const;

  
  /** Sets the column with row span information for @a combo_box to be @a row_span.
   * The row span column contains integers which indicate how many rows
   * an item should span.
   * 
   * @newin{2,4}
   * @param row_span A column in the model passed during construction.
   */
  void set_row_span_column(int row_span);
  
  /** Returns the column with row span information for @a combo_box.
   * 
   * @newin{2,6}
   * @return The row span column.
   */
  int get_row_span_column() const;

  
  /** Sets the column with column span information for @a combo_box to be
   *  @a column_span. The column span column contains integers which indicate
   * how many columns an item should span.
   * 
   * @newin{2,4}
   * @param column_span A column in the model passed during construction.
   */
  void set_column_span_column(int column_span);
  
  /** Returns the column with column span information for @a combo_box.
   * 
   * @newin{2,6}
   * @return The column span column.
   */
  int get_column_span_column() const;

  
  /** Gets the current value of the :add-tearoffs property.
   * @return The current value of the :add-tearoffs property.
   */
  bool get_add_tearoffs() const;
  
  /** Sets whether the popup menu should have a tearoff 
   * menu item.
   * 
   * @newin{2,6}
   * @param add_tearoffs <tt>true</tt> to add tearoff menu items.
   */
  void set_add_tearoffs(bool add_tearoffs =  true);

  
  /** Gets the current title of the menu in tearoff mode. See
   * set_add_tearoffs().
   * 
   * @newin{2,10}
   * @return The menu's title in tearoff mode. This is an internal copy of the
   * string which must not be freed.
   */
  Glib::ustring get_title() const;
  
  /** Sets the menu's title in tearoff mode.
   * 
   * @newin{2,10}
   * @param title A title for the menu in tearoff mode.
   */
  void set_title(const Glib::ustring& title);

  
  /** Returns whether the combo box grabs focus when it is clicked 
   * with the mouse. See set_focus_on_click().
   * 
   * @newin{2,6}
   * @return <tt>true</tt> if the combo box grabs focus when it is 
   * clicked with the mouse.
   */
  bool get_focus_on_click() const;
  
  /** Sets whether the combo box will grab focus when it is clicked with 
   * the mouse. Making mouse clicks not grab focus is useful in places 
   * like toolbars where you don't want the keyboard focus removed from 
   * the main area of the application.
   * 
   * @newin{2,6}
   * @param focus_on_click Whether the combo box grabs focus when clicked 
   * with the mouse.
   */
  void set_focus_on_click(bool focus_on_click =  true);

/* get/set active item */
  
  /** Returns the index of the currently active item, or -1 if there's no
   * active item. If the model is a non-flat treemodel, and the active item 
   * is not an immediate child of the root of the tree, this function returns 
   * <tt>gtk_tree_path_get_indices (path)[0]</tt>, where 
   * <tt>path</tt> is the Gtk::TreePath of the active item.
   * 
   * @newin{2,4}
   * @return An integer which is the index of the currently active item, 
   * or -1 if there's no active item.
   */
  int get_active_row_number() const;

  /** Gets an iterator that points to the current active item, if it exists.
   * @result The iterator.
   */
  TreeModel::iterator get_active();
  
  /** Gets an iterator that points to the current active item, if it exists.
   * @result The iterator.
   */
  TreeModel::const_iterator get_active() const;
  
    
  /** Sets the active item of @a combo_box to be the item at @a index.
   * 
   * @newin{2,4}
   * @param index An index in the model passed during construction, or -1 to have
   * no active item.
   */
  void set_active(int index);
  
  /** Sets the current active item to be the one referenced by @a iter, or
   * unsets the active item if @a iter is <tt>0</tt>.
   * 
   * @newin{2,4}
   * @param iter The Gtk::TreeIter, or <tt>0</tt>.
   */
  void set_active(const TreeModel::iterator& iter);
  
  //TODO: See https://bugzilla.gnome.org/show_bug.cgi?id=612396#c30
  /** Get the text in the entry, if there is an entry.
   *
   * @newin{2,24}
   */
  Glib::ustring get_entry_text() const;

  /** Causes no item to be active. See also set_active().
   */
  void unset_active();

  
  /** Returns the Gtk::TreeModel which is acting as data source for @a combo_box.
   * 
   * @newin{2,4}
   * @return A Gtk::TreeModel which was passed
   * during construction.
   */
  Glib::RefPtr<TreeModel> get_model();
  
  /** Returns the Gtk::TreeModel which is acting as data source for @a combo_box.
   * 
   * @newin{2,4}
   * @return A Gtk::TreeModel which was passed
   * during construction.
   */
  Glib::RefPtr<const TreeModel> get_model() const;
  
  /** Sets the model used by @a combo_box to be @a model. Will unset a previously set
   * model (if applicable). Use unset_model() to unset the old model.
   * 
   * Note that this function does not clear the cell renderers, you have to
   * call Gtk::CellLayout::clear() yourself if you need to set up different
   * cell renderers for the new model.
   * 
   * @newin{2,4}
   * @param model A Gtk::TreeModel.
   */
  void set_model(const Glib::RefPtr<TreeModel>& model);

  /** Remove the model from the ComboBox.
   *
   * @see set_model().
   *
   * @newin{2,16}
   */
  void unset_model();

  typedef TreeView::SlotRowSeparator SlotRowSeparator;  
  
  /** Sets the row separator function, which is used to determine whether a row should be drawn as a separator. 
   * See also unset_row_separator_func().
   * 
   * @param slot The callback.
   */
  void set_row_separator_func(const SlotRowSeparator& slot);
  
  /** Causes no separators to be drawn.
   */
  void unset_row_separator_func();
  

  /** Sets whether the dropdown button of the combo box should be
   * always sensitive (Gtk::SENSITIVITY_ON), never sensitive (Gtk::SENSITIVITY_OFF)
   * or only if there is at least one item to display (Gtk::SENSITIVITY_AUTO).
   * 
   * @newin{2,14}
   * @param sensitivity Specify the sensitivity of the dropdown button.
   */
  void set_button_sensitivity(SensitivityType sensitivity);
  
  /** Returns whether the combo box sets the dropdown button
   * sensitive or not when there are no items in the model.
   * 
   * @newin{2,14}
   * @return Gtk::SENSITIVITY_ON if the dropdown button
   * is sensitive when the model is empty, Gtk::SENSITIVITY_OFF
   * if the button is always insensitive or
   * Gtk::SENSITIVITY_AUTO if it is only sensitive as long as
   * the model has one item to be selected.
   */
  SensitivityType get_button_sensitivity() const;

  
  /** Returns whether the combo box has an entry.
   * 
   * @newin{2,24}
   * @return Whether there is an entry in @a combo_box.
   */
  bool get_has_entry() const;

  
  /** Sets the model column which @a combo_box should use to get strings from
   * to be @a text_column. The column @a text_column in the model of @a combo_box
   * must be of type TYPE_STRING.
   * 
   * This is only relevant if @a combo_box has been created with
   * Gtk::ComboBox:has-entry as <tt>true</tt>.
   * 
   * @newin{2,24}
   * @param text_column A column in @a model to get the strings from for
   * the internal entry.
   */
  void set_entry_text_column(const TreeModelColumnBase& text_column) const;
  
  /** Sets the model column which @a combo_box should use to get strings from
   * to be @a text_column. The column @a text_column in the model of @a combo_box
   * must be of type TYPE_STRING.
   * 
   * This is only relevant if @a combo_box has been created with
   * Gtk::ComboBox:has-entry as <tt>true</tt>.
   * 
   * @newin{2,24}
   * @param text_column A column in @a model to get the strings from for
   * the internal entry.
   */
  void set_entry_text_column(int text_column);

  
  /** Returns the column which @a combo_box is using to get the strings
   * from to display in the internal entry.
   * 
   * @newin{2,24}
   * @return A column in the data source model of @a combo_box.
   */
  int get_entry_text_column() const;

  
  /** Pops up the menu or dropdown list of @a combo_box. 
   * 
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   * 
   * @newin{2,4}
   */
  void popup();
  
  /** Hides the menu or dropdown list of @a combo_box.
   * 
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   * 
   * @newin{2,4}
   */
  void popdown();

  
  /** Gets the accessible object corresponding to the combo box's popup.
   * 
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   * 
   * @newin{2,6}
   * @return The accessible object corresponding
   * to the combo box's popup.
   */

#ifdef  GTKMM_ATKMM_ENABLED
  Glib::RefPtr<Atk::Object> get_popup_accessible();
#endif //  GTKMM_ATKMM_ENABLED

  
  /** Gets the accessible object corresponding to the combo box's popup.
   * 
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   * 
   * @newin{2,6}
   * @return The accessible object corresponding
   * to the combo box's popup.
   */

#ifdef  GTKMM_ATKMM_ENABLED
  Glib::RefPtr<const Atk::Object> get_popup_accessible() const;
#endif //  GTKMM_ATKMM_ENABLED


   //These are in ComboBoxText.

  /** @see Bin::get_child().
   * @newin{2,24}
   */
  Entry* get_entry();

  /** @see Bin::get_child().
   * @newin{2,24}
   */
  const Entry* get_entry() const;
  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The model for the combo box.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<TreeModel> > property_model() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The model for the combo box.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> > property_model() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Wrap width for laying out the items in a grid.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_wrap_width() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Wrap width for laying out the items in a grid.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_wrap_width() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** TreeModel column containing the row span values.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_row_span_column() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** TreeModel column containing the row span values.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_row_span_column() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** TreeModel column containing the column span values.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_column_span_column() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** TreeModel column containing the column span values.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_column_span_column() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The item which is currently active.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_active() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The item which is currently active.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_active() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether dropdowns should have a tearoff menu item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_add_tearoffs() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether dropdowns should have a tearoff menu item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_add_tearoffs() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the combo box draws a frame around the child.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_has_frame() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the combo box draws a frame around the child.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_has_frame() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the combo box grabs focus when it is clicked with the mouse.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_focus_on_click() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the combo box grabs focus when it is clicked with the mouse.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_focus_on_click() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** A title that may be displayed by the window manager when the popup is torn-off.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_tearoff_title() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** A title that may be displayed by the window manager when the popup is torn-off.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_tearoff_title() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the combo's dropdown is shown.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_popup_shown() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the dropdown button is sensitive when the model is empty.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<SensitivityType> property_button_sensitivity() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the dropdown button is sensitive when the model is empty.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<SensitivityType> property_button_sensitivity() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /** The changed signal gets emitted when the active
   * item is changed. This can be due to the user selecting
   * a different item from the list, or due to a 
   * call to set_active_iter().
   *
   * @par Prototype:
   * <tt>void on_my_%changed()</tt>
   */

  Glib::SignalProxy0< void > signal_changed();


  //Key-binding signals:
  
    
};


} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ComboBox
   */
  Gtk::ComboBox* wrap(GtkComboBox* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_COMBOBOX_H */

