// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GLIBMM_OPTIONCONTEXT_H
#define _GLIBMM_OPTIONCONTEXT_H


/* Copyright (C) 2004 The glibmm Development Team
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


#include <glibmm/optionentry.h>
#include <glibmm/optiongroup.h>
#include <glibmm/error.h>
#include <sigc++/signal.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GOptionContext GOptionContext; }
#endif


namespace Glib
{

/** Exception class for options.
 */
class OptionError : public Glib::Error
{
public:
  /**  @var Code UNKNOWN_OPTION
   * An option was not known to the parser.
   * This error will only be reported, if the parser hasn't been instructed
   * to ignore unknown options, see g_option_context_set_ignore_unknown_options().
   * 
   *  @var Code BAD_VALUE
   * A value couldn't be parsed.
   * 
   *  @var Code FAILED
   * A OptionArgFunc callback failed.
   * 
   *  @enum Code
   * 
   * %Error codes returned by option parsing.
   */
  enum Code
  {
    UNKNOWN_OPTION,
    BAD_VALUE,
    FAILED
  };

  OptionError(Code error_code, const Glib::ustring& error_message);
  explicit OptionError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** An OptionContext defines and parses commandline options, using OptionGroup%s and \link OptionEntry option entries \endlink.
 *
 * It supports short and long commandline options, as shown in the following example:
 *
 * <tt>testtreemodel -r 1 --max-size 20 --rand --display=:1.0 -vb -- file1 file2</tt>
 *
 * The example demonstrates a number of features of the GOption
 * commandline parser
 * - Options can be single letters, prefixed by a single dash.
     Multiple short options can be grouped behind a single dash.
 * - Long options are prefixed by two consecutive dashes.
 * - Options can have an extra argument, which can be a number, a string or
 *   a filename. For long options, the extra argument can be appended with
 *   an equals sign after the option name, which is useful if the extra
 *   argument starts with a dash, which would otherwise cause it to be
 *   interpreted as another option.
 * - Non-option arguments are returned to the application as rest arguments.
 * - An argument consisting solely of two dashes turns off further parsing,
 *   any remaining arguments (even those starting with a dash) are returned
 *   to the application as rest arguments.
 *
 * The OptionContext groups options in OptionGroups, which makes it easy to
 * incorporate options from multiple sources. The intended use for this is
 * to let applications collect option groups from the libraries it uses,
 * add them to their OptionContext, and parse all options by a single call
 * to parse(). See Gtk::Main::add_gtk_option_group(), for an example.
 *
 * Add options by creating OptionEntry instances and appropriately-typed variables,
 * and adding them to an OptionGroup with OptionGroup::add_entry() or 
 * OptionGroup::add_entry_filename(). The option group should then be added to
 * the OptionContext with set_main_group() or add_group().
 *
 * You might find it convenient to derive your own class from OptionGroup to
 * contain these OptionEntry instances and member variables.
 *
 * If an option is of type string (see OptionGroup::add_entry()) or filename
 * (see OptionGroup::add_entry_filename()), OptionContext takes
 * care of converting it to the right encoding. strings are returned in
 * UTF-8 encoding and filenames are returned in the GLib filename encoding.
 * Note that this only works if setlocale() has been called before
 * OptionContext::parse().
 *
 * OptionContext can automatically generate nicely formatted help output. Unless it is 
 * explicitly turned off with set_help_enabled(), this will recognize
 * the --help, -?, --help-all and --help-groupname options
 * (where groupname is the name of an OptionGroup) and write suitable text to
 * stdout.
 *
 *
 */
class OptionContext
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef OptionContext CppObjectType;
  typedef GOptionContext BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

  
public:

  /** Creates a new option context.
   * @param parameter_string A string which is displayed in the first line of --help output, after programname [OPTION...]
   */
  explicit OptionContext(const Glib::ustring& parameter_string = Glib::ustring());

  //Note that, unlike Glib::Wrap(), this would create a second C++ instance for the same C instance,u
  //so it should be used carefully. For instance you could not access data in a derived class via this second instance.
  explicit OptionContext(GOptionContext* castitem, bool take_ownership = false);

  //TODO?:
  //OptionContext(const OptionContext& other) = delete;
  //OptionContext& operator=(const OptionContext& other) = delete;

  OptionContext(OptionContext&& other) noexcept;
  OptionContext& operator=(OptionContext&& other) noexcept;

  virtual ~OptionContext();

  
  /** Enables or disables automatic generation of `--help` output.
   * By default, g_option_context_parse() recognizes `--help`, `-h`,
   * `-?`, `--help-all` and `--help-groupname` and creates suitable
   * output to stdout.
   * 
   * @newin{2,6}
   * 
   * @param help_enabled <tt>true</tt> to enable `--help`, <tt>false</tt> to disable it.
   */
  void set_help_enabled(bool help_enabled =  true);
  
  /** Returns whether automatic `--help` generation
   * is turned on for @a context. See g_option_context_set_help_enabled().
   * 
   * @newin{2,6}
   * 
   * @return <tt>true</tt> if automatic help generation is turned on.
   */
  bool get_help_enabled() const;
  
  /** Sets whether to ignore unknown options or not. If an argument is
   * ignored, it is left in the @a argv array after parsing. By default,
   * g_option_context_parse() treats unknown options as error.
   * 
   * This setting does not affect non-option arguments (i.e. arguments
   * which don't start with a dash). But note that GOption cannot reliably
   * determine whether a non-option belongs to a preceding unknown option.
   * 
   * @newin{2,6}
   * 
   * @param ignore_unknown <tt>true</tt> to ignore unknown options, <tt>false</tt> to produce
   * an error when unknown options are met.
   */
  void set_ignore_unknown_options(bool ignore_unknown =  true);
  
  /** Returns whether unknown options are ignored or not. See
   * g_option_context_set_ignore_unknown_options().
   * 
   * @newin{2,6}
   * 
   * @return <tt>true</tt> if unknown options are ignored.
   */
  bool get_ignore_unknown_options() const;

  
  /** Sets strict POSIX mode.
   * 
   * By default, this mode is disabled.
   * 
   * In strict POSIX mode, the first non-argument parameter encountered
   * (eg: filename) terminates argument processing.  Remaining arguments
   * are treated as non-options and are not attempted to be parsed.
   * 
   * If strict POSIX mode is disabled then parsing is done in the GNU way
   * where option arguments can be freely mixed with non-options.
   * 
   * As an example, consider "ls foo -l".  With GNU style parsing, this
   * will list "foo" in long mode.  In strict POSIX style, this will list
   * the files named "foo" and "-l".
   * 
   * It may be useful to force strict POSIX mode when creating "verb
   * style" command line tools.  For example, the "gsettings" command line
   * tool supports the global option "--schemadir" as well as many
   * subcommands ("get", "set", etc.) which each have their own set of
   * arguments.  Using strict POSIX mode will allow parsing the global
   * options up to the verb name while leaving the remaining options to be
   * parsed by the relevant subcommand (which can be determined by
   * examining the verb name, which should be present in argv[1] after
   * parsing).
   * 
   * @newin{2,44}
   * 
   * @param strict_posix The new value.
   */
  void set_strict_posix(bool strict_posix =  true);
  
  /** Returns whether strict POSIX code is enabled.
   * 
   * See g_option_context_set_strict_posix() for more information.
   * 
   * @newin{2,44}
   * 
   * @return <tt>true</tt> if strict POSIX is enabled, <tt>false</tt> otherwise.
   */
  bool get_strict_posix() const;

 
  /** Parses the command line arguments, recognizing options
   * which have been added to @a context. A side-effect of
   * calling this function is that g_set_prgname() will be
   * called.
   * 
   * If the parsing is successful, any parsed arguments are
   * removed from the array and @a argc and @a argv are updated
   * accordingly. A '--' option is stripped from @a argv
   * unless there are unparsed options before and after it,
   * or some of the options after it start with '-'. In case
   * of an error, @a argc and @a argv are left unmodified.
   * 
   * If automatic `--help` support is enabled
   * (see g_option_context_set_help_enabled()), and the
   *  @a argv array contains one of the recognized help options,
   * this function will produce help output to stdout and
   * call `exit (0)`.
   * 
   * Note that function depends on the [current locale][setlocale] for
   * automatic character set conversion of string and filename
   * arguments.
   * 
   * @newin{2,6}
   * 
   * @param argc A pointer to the number of command line arguments.
   * @param argv A pointer to the array of command line arguments.
   * @return <tt>true</tt> if the parsing was successful,
   * <tt>false</tt> if an error occurred.
   */
  bool parse(int& argc, char**& argv);

  //TODO: Document this as useful (only?) with the result from g_win32_get_command_line?
  //goption.c has example code that suggests always using this, and ifdefing for G_OS_WIN32, with a g_strdupv for the non-win32 case.
  //Presumably we cannot hide that ifdeffing from application code because the argument-removal would be invisible to the caller.
  //So can we hide it for people who don't care about arguments being removed from argv?
  //TODO? _WRAP_METHOD(bool parse(char**& argv), g_option_context_parse_strv, errthrow)

  //g_option_context_add_main_entries(), just creates a group internally, adds them to it, and does a set_main_group()
  //- a group without callbacks seems to do some simple default parsing.
  

  /** Adds an OptionGroup to the context, so that parsing with context will recognize the options in the group.
   * Note that the group will not be copied, so it should exist for as long as the context exists.
   *
   * @param group The group to add.
   */
  void add_group(OptionGroup& group);
  

  /** Sets an OptionGroup as the main group of the context. This has the same effect as calling add_group(), the only
   * difference is that the options in the main group are treated differently when generating --help output.
   * Note that the group will not be copied, so it should exist for as long as the context exists.
   *
   * @param group The group to add.
   */
  void set_main_group(OptionGroup& group);
  

  //We don't need this (hopefully), and the memory management would be really awkward.
  //OptionGroup& get_main_group();
  //const OptionGroup& get_main_group() const;
  

  /** Returns a formatted, translated help text for the given context.
   * To obtain the text produced by `--help`, call
   * `g_option_context_get_help (context, <tt>true</tt>, <tt>0</tt>)`.
   * To obtain the text produced by `--help-all`, call
   * `g_option_context_get_help (context, <tt>false</tt>, <tt>0</tt>)`.
   * To obtain the help text for an option group, call
   * `g_option_context_get_help (context, <tt>false</tt>, group)`.
   * 
   * @newin{2,14}
   * 
   * @param main_help If <tt>true</tt>, only include the main group.
   * @param group The OptionGroup to create help for, or <tt>0</tt>.
   * @return A newly allocated string containing the help text.
   */
  Glib::ustring get_help(bool main_help, const OptionGroup& group) const;

  /** Returns a formatted, translated help text for the given context.
   * To obtain the text produced by --help, call get_help (true).
   * To obtain the text produced by --help-all, call get_help(false).
   * To obtain the help text for an option group, call get_help(false, group).
   *
   * @param main_help If true, only include the main group.
   * @result string containing the help text.
   */
  Glib::ustring get_help(bool main_help = true) const;

  GOptionContext*       gobj()       { return gobject_; }
  const GOptionContext* gobj() const { return gobject_; }

  
  /** Adds a string to be displayed in `--help` output before the list
   * of options. This is typically a summary of the program functionality.
   * 
   * Note that the summary is translated (see
   * g_option_context_set_translate_func() and
   * g_option_context_set_translation_domain()).
   * 
   * @newin{2,12}
   * 
   * @param summary A string to be shown in --help output before the list of
   *                     options.
   */
  void set_summary(const Glib::ustring& summary);
  
  /** Returns the summary. See g_option_context_set_summary().
   * 
   * @newin{2,12}
   * 
   * @return The summary.
   */
  Glib::ustring get_summary() const;
  
  /** Adds a string to be displayed in `--help` output after the list
   * of options. This text often includes a bug reporting address.
   * 
   * Note that the summary is translated (see
   * g_option_context_set_translate_func()).
   * 
   * @newin{2,12}
   * 
   * @param description A string to be shown in --help output
   *                     after the list of options.
   */
  void set_description(const Glib::ustring& description);
  
  /** Returns the description. See g_option_context_set_description().
   * 
   * @newin{2,12}
   * 
   * @return The description.
   */
  Glib::ustring get_description() const;

  
  /** A convenience function to use gettext() for translating
   * user-visible strings.
   * 
   * @newin{2,12}
   * 
   * @param domain The domain to use.
   */
  void set_translation_domain(const Glib::ustring& domain);

  /**
   * This function is used to translate user-visible strings, for --help output.
   * The function takes an untranslated string and returns a translated string
   */
  typedef sigc::slot<Glib::ustring, const Glib::ustring&> SlotTranslate;

  /**
   * Sets the function which is used to translate user-visible
   * strings, for --help output.  Different groups can use different functions.
   *
   * If you are using gettext(), you only need to set the translation domain,
   * see set_translation_domain().
   *
   * @newin{2,14}
   */
  void set_translate_func (const SlotTranslate& slot);
  

protected:

  GOptionContext* gobject_;
  bool has_ownership_;


};


} // namespace Glib


#endif /* _GLIBMM_OPTIONCONTEXT_H */

