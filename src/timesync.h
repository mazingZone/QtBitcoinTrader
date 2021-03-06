//  This file is part of Qt Bitcoin Trader
//      https://github.com/JulyIGHOR/QtBitcoinTrader
//  Copyright (C) 2013-2018 July IGHOR <julyighor@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  In addition, as a special exception, the copyright holders give
//  permission to link the code of portions of this program with the
//  OpenSSL library under certain conditions as described in each
//  individual source file, and distribute linked combinations including
//  the two.
//
//  You must obey the GNU General Public License in all respects for all
//  of the code used other than OpenSSL. If you modify file(s) with this
//  exception, you may extend this exception to your version of the
//  file(s), but you are not obligated to do so. If you do not wish to do
//  so, delete this exception statement from your version. If you delete
//  this exception statement from all source files in the program, then
//  also delete it here.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef TIMESYNC_H
#define TIMESYNC_H

#include <QObject>
#include <QMutex>

class QThread;
class QElapsedTimer;

class TimeSync : public QObject
{
    Q_OBJECT

public:
    TimeSync();
    ~TimeSync();
    static TimeSync* global();
    static quint32 getTimeT();
    static void syncNow();

signals:
    void warningMessage(QString);
    void startSync();

private slots:
    void runThread();
    void getNTPTime();

private:
    QThread* dateUpdateThread;
    QAtomicInt started;
    quint32 startTime;
    QAtomicInt timeShift;
    QElapsedTimer* additionalTimer;
    QMutex mutex;
    int getNTPTimeRetryCount;
};

#endif // TIMESYNC_H
