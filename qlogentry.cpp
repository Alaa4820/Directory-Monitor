#include "qlogentry.h"

QLogEntry::QLogEntry(const QString &filename, const QString &event, const QDateTime &eventTime)
    : _filename(filename), _event(event), _eventTime(eventTime){}


QLogEntry::~QLogEntry(){}

const QString& QLogEntry::filename() const{
    return _filename;
}

const QString& QLogEntry::event() const{
    return _event;
}

const QDateTime& QLogEntry::eventTile() const{
    return _eventTime;
}
