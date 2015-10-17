/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KNWINDOWSEXTRAS_H
#define KNWINDOWSEXTRAS_H

#include <QSystemTrayIcon>

#include "knplatformextras.h"

class QMenu;
class QAction;
class QSystemTrayIcon;
class QWinThumbnailToolBar;
class QWinThumbnailToolButton;
class KNMainWindow;
class KNWindowsExtras : public KNPlatformExtras
{
    Q_OBJECT
public:
    explicit KNWindowsExtras(QObject *parent = 0);

    /*!
     * \brief Reimplemented from KNPlatformExtras::setMainWindow().
     */
    void setMainWindow(QMainWindow *mainWindow) Q_DECL_OVERRIDE;

signals:

public slots:
    /*!
     * \brief Reimplemented from KNPlatformExtras::onActionPlayStateChanged().
     */
    void onActionPlayStateChanged(const bool &isPlay) Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from KNPlatformExtras::onActionMuteStateChanged().
     */
    void onActionMuteStateChanged(const bool &isMute) Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from KNPlatformExtras::onActionLoopStateChanged().
     */
    void onActionLoopStateChanged(const int &loopState) Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from KNPlatformExtras::loadPreference().
     */
    void loadPreference() Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from KNPlatformExtras::savePreference().
     */
    void savePreference() Q_DECL_OVERRIDE;

private slots:
    void retranslate();
    void onActionPlayAndPause();
    void onActionTrayIconActivate(
            const QSystemTrayIcon::ActivationReason &reason);
    void onActionTrayMenuActionTriggered(const int &index);

private:
    inline void setButtonIcon(const int &index, const QPixmap &icon);
    enum ThumbnailActions
    {
        PlayPrev,
        PlayAndPause,
        PlayNext,
        VolumeUp,
        VolumeDown,
        Mute,
        LoopMode,
        ThumbnailActionsCount
    };
    enum TrayIconMenuActions
        {
            Exit,
            TrayIconMenuActionCount
        };
    QPixmap m_playIcon, m_pauseIcon, m_muteOn, m_muteOff,
            m_loopStates[LoopStateButtonStateCount];
    QAction *m_trayIconActions[TrayIconMenuActionCount];
    QWinThumbnailToolButton *m_thumbnailButtons[ThumbnailActionsCount];
    QWinThumbnailToolBar *m_thumbnailToolbar;
    QSystemTrayIcon *m_trayIcon;
    QMenu *m_trayIconMenu;
    KNMainWindow *m_mainWindow;
    bool m_isStatePlay;
};

#endif // KNWINDOWSEXTRAS_H
