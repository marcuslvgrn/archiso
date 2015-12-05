// -*- c++ -*-
// Generated by gmmproc 2.46.2 -- DO NOT MODIFY!
#ifndef _GLIBMM_SPAWN_H
#define _GLIBMM_SPAWN_H


/* Copyright (C) 2002 The gtkmm Development Team
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


#include <glibmmconfig.h>
#include <glibmm/arrayhandle.h>
#include <glibmm/error.h>
#include <sigc++/sigc++.h>
#include <string>

namespace Glib
{

typedef GPid Pid;

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/** 
 *  @var SpawnFlags SPAWN_DEFAULT
 * No flags, default behaviour.
 * 
 *  @var SpawnFlags SPAWN_LEAVE_DESCRIPTORS_OPEN
 * The parent's open file descriptors will
 * be inherited by the child; otherwise all descriptors except stdin,
 * stdout and stderr will be closed before calling exec() in the child.
 * 
 *  @var SpawnFlags SPAWN_DO_NOT_REAP_CHILD
 * The child will not be automatically reaped;
 * you must use g_child_watch_add() yourself (or call waitpid() or handle
 * `SIGCHLD` yourself), or the child will become a zombie.
 * 
 *  @var SpawnFlags SPAWN_SEARCH_PATH
 * `argv[0]` need not be an absolute path, it will be
 * looked for in the user's `PATH`.
 * 
 *  @var SpawnFlags SPAWN_STDOUT_TO_DEV_NULL
 * The child's standard output will be discarded,
 * instead of going to the same location as the parent's standard output.
 * 
 *  @var SpawnFlags SPAWN_STDERR_TO_DEV_NULL
 * The child's standard error will be discarded.
 * 
 *  @var SpawnFlags SPAWN_CHILD_INHERITS_STDIN
 * The child will inherit the parent's standard
 * input (by default, the child's standard input is attached to `/dev/null`).
 * 
 *  @var SpawnFlags SPAWN_FILE_AND_ARGV_ZERO
 * The first element of `argv` is the file to
 * execute, while the remaining elements are the actual argument vector
 * to pass to the file. Normally g_spawn_async_with_pipes() uses `argv[0]`
 * as the file to execute, and passes all of `argv` to the child.
 * 
 *  @var SpawnFlags SPAWN_SEARCH_PATH_FROM_ENVP
 * If `argv[0]` is not an abolute path,
 * it will be looked for in the `PATH` from the passed child environment.
 * @newin{2,34}
 * 
 *  @var SpawnFlags SPAWN_CLOEXEC_PIPES
 * Create all pipes with the `O_CLOEXEC` flag set.
 * @newin{2,40}
 * 
 *  @enum SpawnFlags
 * 
 * Flags passed to g_spawn_sync(), g_spawn_async() and g_spawn_async_with_pipes().
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%SpawnFlags operator|(SpawnFlags, SpawnFlags)</tt><br>
 * <tt>%SpawnFlags operator&(SpawnFlags, SpawnFlags)</tt><br>
 * <tt>%SpawnFlags operator^(SpawnFlags, SpawnFlags)</tt><br>
 * <tt>%SpawnFlags operator~(SpawnFlags)</tt><br>
 * <tt>%SpawnFlags& operator|=(SpawnFlags&, SpawnFlags)</tt><br>
 * <tt>%SpawnFlags& operator&=(SpawnFlags&, SpawnFlags)</tt><br>
 * <tt>%SpawnFlags& operator^=(SpawnFlags&, SpawnFlags)</tt><br>
 */
enum SpawnFlags
{
  SPAWN_DEFAULT = 0x0,
  SPAWN_LEAVE_DESCRIPTORS_OPEN = 1 << 0,
  SPAWN_DO_NOT_REAP_CHILD = 1 << 1,
  SPAWN_SEARCH_PATH = 1 << 2,
  SPAWN_STDOUT_TO_DEV_NULL = 1 << 3,
  SPAWN_STDERR_TO_DEV_NULL = 1 << 4,
  SPAWN_CHILD_INHERITS_STDIN = 1 << 5,
  SPAWN_FILE_AND_ARGV_ZERO = 1 << 6,
  SPAWN_SEARCH_PATH_FROM_ENVP = 1 << 7,
  SPAWN_CLOEXEC_PIPES = 1 << 8
};

/** @ingroup glibmmEnums */
inline SpawnFlags operator|(SpawnFlags lhs, SpawnFlags rhs)
  { return static_cast<SpawnFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline SpawnFlags operator&(SpawnFlags lhs, SpawnFlags rhs)
  { return static_cast<SpawnFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline SpawnFlags operator^(SpawnFlags lhs, SpawnFlags rhs)
  { return static_cast<SpawnFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline SpawnFlags operator~(SpawnFlags flags)
  { return static_cast<SpawnFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline SpawnFlags& operator|=(SpawnFlags& lhs, SpawnFlags rhs)
  { return (lhs = static_cast<SpawnFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline SpawnFlags& operator&=(SpawnFlags& lhs, SpawnFlags rhs)
  { return (lhs = static_cast<SpawnFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline SpawnFlags& operator^=(SpawnFlags& lhs, SpawnFlags rhs)
  { return (lhs = static_cast<SpawnFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** @defgroup Spawn Spawning Processes
 * Process launching with fork()/exec().
 * @{
 */

/** %Exception class for errors occuring when spawning processes.
 */
class SpawnError : public Glib::Error
{
public:
  /**  @var Code FORK
   * Fork failed due to lack of memory.
   * 
   *  @var Code READ
   * Read or select on pipes failed.
   * 
   *  @var Code CHDIR
   * Changing to working directory failed.
   * 
   *  @var Code ACCES
   * Execv() returned `EACCES`.
   * 
   *  @var Code PERM
   * Execv() returned `EPERM`.
   * 
   *  @var Code TOO_BIG
   * Execv() returned `E2BIG`.
   * 
   *  @var Code TOOBIG
   * Deprecated alias for SPAWN_ERROR_TOO_BIG.
   * 
   *  @var Code NOEXEC
   * Execv() returned `ENOEXEC`.
   * 
   *  @var Code NAMETOOLONG
   * Execv() returned `ENAMETOOLONG`.
   * 
   *  @var Code NOENT
   * Execv() returned `ENOENT`.
   * 
   *  @var Code NOMEM
   * Execv() returned `ENOMEM`.
   * 
   *  @var Code NOTDIR
   * Execv() returned `ENOTDIR`.
   * 
   *  @var Code LOOP
   * Execv() returned `ELOOP`.
   * 
   *  @var Code TXTBUSY
   * Execv() returned `ETXTBUSY`.
   * 
   *  @var Code IO
   * Execv() returned `EIO`.
   * 
   *  @var Code NFILE
   * Execv() returned `ENFILE`.
   * 
   *  @var Code MFILE
   * Execv() returned `EMFILE`.
   * 
   *  @var Code INVAL
   * Execv() returned `EINVAL`.
   * 
   *  @var Code ISDIR
   * Execv() returned `EISDIR`.
   * 
   *  @var Code LIBBAD
   * Execv() returned `ELIBBAD`.
   * 
   *  @var Code FAILED
   * Some other fatal failure,
   * `error->message` should explain.
   * 
   *  @enum Code
   * 
   * %Error codes returned by spawning processes.
   */
  enum Code
  {
    FORK,
    READ,
    CHDIR,
    ACCES,
    PERM,
    TOO_BIG,
    TOOBIG = TOO_BIG,
    NOEXEC,
    NAMETOOLONG,
    NOENT,
    NOMEM,
    NOTDIR,
    LOOP,
    TXTBUSY,
    IO,
    NFILE,
    MFILE,
    INVAL,
    ISDIR,
    LIBBAD,
    FAILED
  };

  SpawnError(Code error_code, const Glib::ustring& error_message);
  explicit SpawnError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** For instance,<br>
 *   void on_child_setup();
 */
typedef sigc::slot<void> SlotSpawnChildSetup;

/** Executes a child program asynchronously (your program will not
 * block waiting for the child to exit). The child program is
 * specified by the only argument that must be provided, @a argv.
 * The first string in @a argv is of
 * course the name of the program to execute. By default, the name of
 * the program must be a full path; the PATH shell variable
 * will only be searched if you pass the SPAWN_SEARCH_PATH flag.
 *
 * On Windows, note that all the string or string vector arguments to
 * this function and the other spawn*() functions are in UTF-8, the
 * GLib file name encoding. Unicode characters that are not part of
 * the system codepage passed in these arguments will be correctly
 * available in the spawned program only if it uses wide character API
 * to retrieve its command line. For C programs built with Microsoft's
 * tools it is enough to make the program have a wmain() instead of
 * main(). wmain() has a wide character argument vector as parameter.
 *
 * At least currently, mingw doesn't support wmain(), so if you use
 * mingw to develop the spawned program, it will have to call the
 * undocumented function __wgetmainargs() to get the wide character
 * argument vector and environment. See gspawn-win32-helper.c in the
 * GLib sources or init.c in the mingw runtime sources for a prototype
 * for that function. Alternatively, you can retrieve the Win32 system
 * level wide character command line passed to the spawned program
 * using the GetCommandLineW() function.
 *
 * On Windows the low-level child process creation API
 * CreateProcess() doesn't use argument vectors,
 * but a command line. The C runtime library's
 * spawn*() family of functions (which
 * spawn_async_with_pipes() eventually calls) paste the argument
 * vector elements together into a command line, and the C runtime startup code
 * does a corresponding reconstruction of an argument vector from the
 * command line, to be passed to main(). Complications arise when you have
 * argument vector elements that contain spaces of double quotes. The
 * spawn*() functions don't do any quoting or
 * escaping, but on the other hand the startup code does do unquoting
 * and unescaping in order to enable receiving arguments with embedded
 * spaces or double quotes. To work around this asymmetry,
 * spawn_async_with_pipes() will do quoting and escaping on argument
 * vector elements that need it before calling the C runtime
 * spawn() function.
 *
 * @a envp is a lists of strings, where each string
 * has the form KEY=VALUE. This will become
 * the child's environment.
 *
 * @a flags should be the bitwise OR of any flags you want to affect the
 * function's behaviour. The SPAWN_DO_NOT_REAP_CHILD flags means that
 * the child will not automatically be reaped; you must use a
 * ChildWatch source to be notified about the death of the child
 * process. Eventually you must call spawn_close_pid() on the
 * @a child_pid, in order to free resources which may be associated
 * with the child process. (On Unix, using a ChildWatch source is
 * equivalent to calling waitpid() or handling the SIGCHLD signal
 * manually. On Windows, calling spawn_close_pid() is equivalent
 * to calling CloseHandle() on the process handle returned in
 * @a child_pid).
 *
 * PAWN_LEAVE_DESCRIPTORS_OPEN means that the parent's open file
 * descriptors will be inherited by the child; otherwise all
 * descriptors except stdin/stdout/stderr will be closed before
 * calling exec() in the child. SPAWN_SEARCH_PATH
 * means that argv[0] need not be an absolute path, it
 * will be looked for in the user's PATH.
 * SPAWN_STDOUT_TO_DEV_NULL means that the child's standard output will
 * be discarded, instead of going to the same location as the parent's
 * standard output. If you use this flag, @a standard_output must be NULL.
 * SPAWN_STDERR_TO_DEV_NULL means that the child's standard error
 * will be discarded, instead of going to the same location as the parent's
 * standard error. If you use this flag, @a standard_error must be NULL.
 * SPAWN_CHILD_INHERITS_STDIN means that the child will inherit the parent's
 * standard input (by default, the child's standard input is attached to
 * /dev/null). If you use this flag, @a standard_input must be NULL.
 * G_SPAWN_FILE_AND_ARGV_ZERO means that the first element of @a argv is
 * the file to execute, while the remaining elements are the
 * actual argument vector to pass to the file. Normally
 * spawn_async_with_pipes() uses argv[0] as the file to execute, and
 * passes all of @a argv to the child.
 *
 * @a child_setup is a callback slot. On POSIX
 * platforms, the function is called in the child after GLib has
 * performed all the setup it plans to perform (including creating
 * pipes, closing file descriptors, etc.) but before calling
 * exec(). That is, @a child_setup is called just
 * before calling exec() in the child. Obviously
 * actions taken in this function will only affect the child, not the
 * parent. On Windows, there is no separate fork() and exec()
 * functionality. Child processes are created and run with
 * a single API call, CreateProcess(). @a child_setup is
 * called in the parent process just before creating the child
 * process. You should carefully consider what you do in @a child_setup
 * if you intend your software to be portable to Windows.
 *
 * If non-NULL, @a child_pid will on Unix be filled with the child's
 * process ID. You can use the process ID to send signals to the
 * child, or to use child_watch_add() (or waitpid()) if you specified the
 * SPAWN_DO_NOT_REAP_CHILD flag. On Windows, @a child_pid will be
 * filled with a handle to the child process only if you specified the
 * SPAWN_DO_NOT_REAP_CHILD flag. You can then access the child
 * process using the Win32 API, for example wait for its termination
 * with the WaitFor*() functions, or examine its
 * exit code with GetExitCodeProcess(). You should close the handle
 * with CloseHandle() or spawn_close_pid() when you no longer need it.
 *
 * If non-NULL, the @a standard_input, @a standard_output, @a standard_error
 * locations will be filled with file descriptors for writing to the child's
 * standard input or reading from its standard output or standard error.
 * The caller of pawn_async_with_pipes() must close these file descriptors
 * when they are no longer in use. If these parameters are NULL, the corresponding
 * pipe won't be created.
 *
 * If @a standard_input is NULL, the child's standard input is attached to
 * /dev/null unless SPAWN_CHILD_INHERITS_STDIN is set.
 *
 * If @a standard_error is NULL, the child's standard error goes to the same
 * location as the parent's standard error unless SPAWN_STDERR_TO_DEV_NULL
 * is set.
 *
 * If @a standard_output is NULL, the child's standard output goes to the same
 * location as the parent's standard output unless SPAWN_STDOUT_TO_DEV_NULL
 * is set.
 *
 * If @a child_pid is not NULL and an error does not occur then the returned
 * pid must be closed using spawn_close_pid().
 *
 * @note
 * If you are writing a gtkmm application, and the program you
 * are spawning is a graphical application, too, then you may
 * want to use spawn_on_screen_with_pipes() instead to ensure that
 * the spawned program opens its windows on the right screen.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit the parent's, in the GLib file name encoding.
 * @param argv Child's argument vector.
 * @param envp Child's environment.
 * @param flags Flags from SpawnFlags
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param child_pid Return location for child process ID, or NULL.
 * @param standard_input Return location for file descriptor to write to child's stdin, or NULL.
 * @param standard_output Return location for file descriptor to read child's stdout, or NULL.
 * @param standard_error Return location for file descriptor to read child's stderr, or NULL.
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users. If an error occurs, @a child_pid, @a standard_input, @a standard_output,
 * and @a standard_error will not be filled with valid values.
 */
void spawn_async_with_pipes(const std::string& working_directory,
                            const Glib::ArrayHandle<std::string>& argv,
                            const Glib::ArrayHandle<std::string>& envp,
                            SpawnFlags flags = SPAWN_DEFAULT,
                            const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                            Pid* child_pid = nullptr,
                            int* standard_input = nullptr,
                            int* standard_output = nullptr,
                            int* standard_error = nullptr);

/** Like the main spawn_async_with_pipes() method, but inheriting the parent's environment.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit the parent's, in the GLib file name encoding.
 * @param argv Child's argument vector.
 * @param flags Flags from SpawnFlags
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param child_pid Return location for child process ID, or NULL.
 * @param standard_input Return location for file descriptor to write to child's stdin, or NULL.
 * @param standard_output Return location for file descriptor to read child's stdout, or NULL.
 * @param standard_error Return location for file descriptor to read child's stderr, or NULL.
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users. If an error occurs, @a child_pid, @a standard_input, @a standard_output,
 * and @a standard_error will not be filled with valid values.
 */
void spawn_async_with_pipes(const std::string& working_directory,
                            const Glib::ArrayHandle<std::string>& argv,
                            SpawnFlags flags = SPAWN_DEFAULT,
                            const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                            Pid* child_pid = nullptr,
                            int* standard_input = nullptr,
                            int* standard_output = nullptr,
                            int* standard_error = nullptr);

/** See spawn_async_with_pipes() for a full description. This function
 * simply calls the spawn_async_with_pipes() without any pipes.
 *
 * @note
 * If you are writing a GTK+ application, and the program you
 * are spawning is a graphical application, too, then you may
 * want to use gdk_spawn_on_screen() instead to ensure that
 * the spawned program opens its windows on the right screen.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit parent's.
 * @param argv Child's argument vector.
 * @param envp Child's environment.
 * @param flags Flags from SpawnFlags.
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param child_pid Return location for child process ID, or NULL
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users.
 */
void spawn_async(const std::string& working_directory,
                 const Glib::ArrayHandle<std::string>& argv,
                 const Glib::ArrayHandle<std::string>& envp,
                 SpawnFlags flags = SPAWN_DEFAULT,
                 const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                 Pid* child_pid = nullptr);

/** Like the main spawn_async() method, but inheriting the parent's environment.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit parent's.
 * @param argv Child's argument vector.
 * @param flags Flags from SpawnFlags.
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param child_pid Return location for child process ID, or NULL
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users.
 */
void spawn_async(const std::string& working_directory,
                 const Glib::ArrayHandle<std::string>& argv,
                 SpawnFlags flags = SPAWN_DEFAULT,
                 const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                 Pid* child_pid = nullptr);

/** Executes a child synchronously (waits for the child to exit before returning).
 * All output from the child is stored in @a standard_output and @a standard_error,
 * if those parameters are non-NULL. Note that you must set the
 * SPAWN_STDOUT_TO_DEV_NULL and SPAWN_STDERR_TO_DEV_NULL flags when
 * passing NULL for @a standard_output and @a standard_error.
 * If @a exit_status is non-NULL, the exit status of the child is stored
 * there as it would be returned by waitpid(); standard UNIX macros such
 * as WIFEXITED() and WEXITSTATUS() must be used to evaluate the exit status.
 * Note that this function calls waitpid() even if @a exit_status is NULL, and
 * does not accept the SPAWN_DO_NOT_REAP_CHILD flag.
 * If an error occurs, no data is returned in @a standard_output,
 * @a standard_error, or @a exit_status.
 *
 * This function calls spawn_async_with_pipes() internally; see that
 * function for full details on the other parameters and details on
 * how these functions work on Windows.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit the parent's, in the GLib file name encoding.
 * @param argv Child's argument vector.
 * @param envp Child's environment.
 * @param flags Flags from SpawnFlags
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param standard_output Return location for file descriptor to read child's stdout, or NULL.
 * @param standard_error Return location for file descriptor to read child's stderr, or NULL.
 * @param exit_status Return location for child exit status, as returned by waitpid(), or NULL
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users. If an error occurs, @a child_pid, @a standard_input, @a standard_output,
 * and @a standard_error will not be filled with valid values.
 */
void spawn_sync(const std::string& working_directory,
                const Glib::ArrayHandle<std::string>& argv,
                const Glib::ArrayHandle<std::string>& envp,
                SpawnFlags flags = SPAWN_DEFAULT,
                const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                std::string* standard_output = nullptr,
                std::string* standard_error = nullptr,
                int* exit_status = nullptr);

/** Like the main spawn_sync() method, but inheriting the parent's environment.
 *
 * @param working_directory Child's current working directory, or an empty string to inherit the parent's, in the GLib file name encoding.
 * @param argv Child's argument vector.
 * @param flags Flags from SpawnFlags
 * @param child_setup Slot to run in the child just before exec(), or an empty slot.
 * @param standard_output Return location for file descriptor to read child's stdout, or NULL.
 * @param standard_error Return location for file descriptor to read child's stderr, or NULL.
 * @param exit_status Return location for child exit status, as returned by waitpid(), or NULL
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users. If an error occurs, @a child_pid, @a standard_input, @a standard_output,
 * and @a standard_error will not be filled with valid values.
 */
void spawn_sync(const std::string& working_directory,
                const Glib::ArrayHandle<std::string>& argv,
                SpawnFlags flags = SPAWN_DEFAULT,
                const SlotSpawnChildSetup& child_setup = SlotSpawnChildSetup(),
                std::string* standard_output = nullptr,
                std::string* standard_error = nullptr,
                int* exit_status = nullptr);

/** A simple version of spawn_async() that parses a command line with
 * shell_parse_argv() and passes it to spawn_async(). It runs a
 * command line in the background. Unlike spawn_async(), the
 * SPAWN_SEARCH_PATH flag is enabled, other flags are not. Note
 * that SPAWN_SEARCH_PATH can have security implications, so
 * consider using spawn_async() directly if appropriate.
 *
 * The same concerns on Windows apply as for spawn_command_line_sync().
 *
 * @param command_line A command line.
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users.
 * @throws ShellError If the command line could not be parsed.
 */
void spawn_command_line_async(const std::string& command_line);

/** A simple version of spawn_sync() with little-used parameters
 * removed, taking a command line instead of an argument vector.  See
 * spawn_sync() for full details. @a command_line will be parsed by
 * shell_parse_argv(). Unlike spawn_sync(), the SPAWN_SEARCH_PATH flag
 * is enabled. Note that SPAWN_SEARCH_PATH can have security
 * implications, so consider using spawn_sync() directly if
 * appropriate.
 *
 * If @a exit_status is non-NULL, the exit status of the child is stored there as
 * it would be returned by waitpid(); standard UNIX macros such as WIFEXITED()
 * and WEXITSTATUS() must be used to evaluate the exit status.
 *
 * On Windows, please note the implications of shell_parse_argv()
 * parsing @a command_line. Parsing is done according to Unix shell rules, not
 * Windows command interpreter rules.
 * Space is a separator, and backslashes are
 * special. Thus you cannot simply pass a @a command_line containing
 * canonical Windows paths, like "c:\\program files\\app\\app.exe", as
 * the backslashes will be eaten, and the space will act as a
 * separator. You need to enclose such paths with single quotes, like
 * "'c:\\program files\\app\\app.exe' 'e:\\folder\\argument.txt'".
 *
 * @param command_line A command line.
 * @param standard_output Return location for child output.
 * @param standard_error Return location for child errors.
 * @param exit_status Return location for child exit status, as returned by waitpid().
 *
 * @throws SpawnError Errors are reported even if they occur in the child (for example if the
 * executable in argv[0] is not found). Typically
 * the message field of returned errors should be displayed
 * to users.
 * @throws ShellError If the command line could not be parsed.
 */
void spawn_command_line_sync(const std::string& command_line,
                             std::string* standard_output = nullptr,
                             std::string* standard_error = nullptr,
                             int* exit_status = nullptr);

/** On some platforms, notably WIN32, the Pid type represents a resource
 * which must be closed to prevent resource leaking. close_pid()
 * is provided for this purpose. It should be used on all platforms, even
 * though it doesn't do anything under UNIX.
 *
 * @param pid The process identifier to close.
 */
void spawn_close_pid(Pid pid);

/** @} group Spawn */

} // namespace Glib


#endif /* _GLIBMM_SPAWN_H */

