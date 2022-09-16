#ifndef QLOGENTRY_H
#define QLOGENTRY_H

#include <QString>
#include <QDateTime>

class QLogEntry{

public:
    QLogEntry(const QString &filename, const QString &event, const QDateTime &eventTile);
    ~QLogEntry();

    const QString& filename() const;
    const QString& event() const;
    const QDateTime& eventTile() const;

private:
    QString _filename;
    QString _event;
    QDateTime _eventTime;

};

#endif // QLOGENTRY_H
