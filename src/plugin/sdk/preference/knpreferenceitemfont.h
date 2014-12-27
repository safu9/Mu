/*
 * Copyright (C) Kreogist Dev Team <kreogistdevteam@126.com>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#ifndef KNPREFERENCEITEMFONT_H
#define KNPREFERENCEITEMFONT_H

#include "knpreferenceitembase.h"

class QPushButton;
class KNPreferenceItemFont : public KNPreferenceItemBase
{
public:
    explicit KNPreferenceItemFont(QWidget *parent = 0);
    ~KNPreferenceItemFont();
    QVariant defaultValue() const;
    QVariant value() const;

public slots:
    void setDefaultValue(const QVariant &defaultValue);
    void setValue(const QVariant &value);

private slots:
    void onActionSelectFont();
    void updateOverview();

private:
    QLabel *m_fontOverview, *m_previewIcon;
    QFont m_value, m_defaultFont;
    QPushButton *m_changeFont;
};

#endif // KNPREFERENCEITEMFONT_H
