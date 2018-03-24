/*

Copyright (C) 2011-2017 Jacob Dawid

This file is part of Octave.

Octave is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Octave is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

*/

#if defined (HAVE_CONFIG_H)
#  include "config.h"
#endif

#include "documentation-dock-widget.h"

#include "help.h"
#include "interpreter-private.h"

namespace octave
{
  documentation_dock_widget::documentation_dock_widget (QWidget *p)
    : octave_dock_widget (p)
  {
    setObjectName ("DocumentationDockWidget");
    setWindowIcon (QIcon (":/actions/icons/logo.png"));
    set_title (tr ("Documentation"));
    setStatusTip (tr ("See the documentation for help."));

    m_webinfo = new octave::webinfo (this);
    setWidget (m_webinfo);
    setFocusProxy (m_webinfo);

    connect (p, SIGNAL (show_doc_signal (const QString&)),
             this, SLOT (showDoc (const QString&)));
  }

  void documentation_dock_widget::notice_settings (const QSettings *settings)
  {
    m_webinfo->notice_settings (settings);
  }

  void documentation_dock_widget::load_info_file (void)
  {
    octave::help_system& help_sys
      = octave::__get_help_system__ ("doc widget: load_info_file");

    QString info_file = QString::fromStdString (help_sys.info_file ());

    m_webinfo->load_info_file (info_file);
  }

  void documentation_dock_widget::copyClipboard (void)
  {
    m_webinfo->copyClipboard ();
  }

  void documentation_dock_widget::pasteClipboard (void)
  {
    m_webinfo->pasteClipboard ();
  }

  void documentation_dock_widget::selectAll (void)
  {
    m_webinfo->selectAll ();
  }

  void documentation_dock_widget::showDoc (const QString& name)
  {
    // show the doc pane without focus for carrying on typing in the console
    if (! isVisible ())
      setVisible (true);

    raise ();

    m_webinfo->load_ref (name);
  }
}
