/* mime_info.h --- static MIME information for C/C++
 * Copyright (C) 2019 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
 * This file is public domain software.
 */
#ifndef MIME_INFO_H_
#define MIME_INFO_H_        2   /* Version 2 */

#ifdef __cplusplus
    #include <cstring>
    using std::size_t;
#else
    #include <string.h>
#endif

typedef struct mime_info_entry
{
    const char *extension;
    const char *mime;
} mime_info_entry;

static __inline const mime_info_entry *
mime_info_get_table(size_t *count)
{
    static const mime_info_entry s_entries[] =
    {
        { ".3g2", "video/3gpp2" },
        { ".3g2", "audio/3gpp2" },
        { ".3gp", "video/3gpp" },
        { ".3gp", "audio/3gpp" },
        { ".7z", "application/x-7z-compressed" },
        { ".aac", "audio/aac" },
        { ".abw", "application/x-abiword" },
        { ".arc", "application/x-freearc" },
        { ".avi", "video/x-msvideo" },
        { ".azw", "application/vnd.amazon.ebook" },
        { ".bin", "application/octet-stream" },
        { ".bmp", "image/bmp" },
        { ".bz", "application/x-bzip" },
        { ".bz2", "application/x-bzip2" },
        { ".csh", "application/x-csh" },
        { ".css", "text/css" },
        { ".csv", "text/csv" },
        { ".doc", "application/msword" },
        { ".docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document" },
        { ".eot", "application/vnd.ms-fontobject" },
        { ".epub", "application/epub+zip" },
        { ".gif", "image/gif" },
        { ".htm", "text/html" },
        { ".html", "text/html" },
        { ".ico", "image/vnd.microsoft.icon" },
        { ".ics", "text/calendar" },
        { ".jar", "application/java-archive" },
        { ".jpeg", "image/jpeg" },
        { ".jpg", "image/jpeg" },
        { ".js", "text/javascript" },
        { ".json", "application/json" },
        { ".mid", "audio/midi" },
        { ".mid", "audio/x-midi" },
        { ".midi", "audio/midi" },
        { ".midi", "audio/x-midi" },
        { ".mjs", "text/javascript" },
        { ".mp3", "audio/mpeg" },
        { ".mp4", "video/mp4" },
        { ".mp4", "audio/mp4" },
        { ".mp4", "application/mp4" },
        { ".mpeg", "video/mpeg" },
        { ".mpkg", "application/vnd.apple.installer+xml" },
        { ".odp", "application/vnd.oasis.opendocument.presentation" },
        { ".ods", "application/vnd.oasis.opendocument.spreadsheet" },
        { ".odt", "application/vnd.oasis.opendocument.text" },
        { ".oga", "audio/ogg" },
        { ".ogv", "video/ogg" },
        { ".ogx", "application/ogg" },
        { ".otf", "font/otf" },
        { ".pdf", "application/pdf" },
        { ".png", "image/png" },
        { ".ppt", "application/vnd.ms-powerpoint" },
        { ".pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation" },
        { ".rar", "application/x-rar-compressed" },
        { ".rtf", "application/rtf" },
        { ".sh", "application/x-sh" },
        { ".svg", "image/svg+xml" },
        { ".swf", "application/x-shockwave-flash" },
        { ".tar", "application/x-tar" },
        { ".tif", "image/tiff" },
        { ".tiff", "image/tiff" },
        { ".ttf", "font/ttf" },
        { ".txt", "text/plain" },
        { ".vsd", "application/vnd.visio" },
        { ".wav", "audio/wav" },
        { ".weba", "audio/webm" },
        { ".webm", "video/webm" },
        { ".webp", "image/webp" },
        { ".woff", "font/woff" },
        { ".woff2", "font/woff2" },
        { ".xhtml", "application/xhtml+xml" },
        { ".xls", "application/vnd.ms-excel" },
        { ".xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet" },
        { ".xml", "application/xml" },
        { ".xml", "text/xml" },
        { ".xul", "application/vnd.mozilla.xul+xml" },
        { ".zip", "application/zip" },
    };

    *count = (size_t)(sizeof(s_entries) / sizeof(s_entries[0]));
    return s_entries;
}

static __inline const mime_info_entry *
mime_info_find_entry_from_extension(const char *extension)
{
#ifdef __cplusplus
    using namespace std;
#endif
    size_t i, count;
    const mime_info_entry *entries;

    if (*extension == '.')
        ++extension;

    entries = mime_info_get_table(&count);
    for (i = 0; i < count; ++i)
    {
        if (strcmp(&entries[i].extension[1], extension) == 0)
        {
            return &entries[i];
        }
    }

    return NULL;
}

static __inline const mime_info_entry *
mime_info_find_entry_from_mime(const char *mime)
{
#ifdef __cplusplus
    using namespace std;
#endif
    size_t i, count;
    const mime_info_entry *entries;

    entries = mime_info_get_table(&count);
    for (i = 0; i < count; ++i)
    {
        if (strcmp(entries[i].mime, mime) == 0)
        {
            return &entries[i];
        }
    }

    return NULL;
}

static __inline const char *
mime_info_extension_from_mime(const char *mime)
{
    const mime_info_entry *entry;
    entry = mime_info_find_entry_from_mime(mime);
    if (entry)
    {
        return entry->extension;
    }
    return NULL;
}

static __inline const char *
mime_info_mime_from_extension(const char *extension)
{
    const mime_info_entry *entry;
    entry = mime_info_find_entry_from_extension(extension);
    if (entry)
    {
        return entry->mime;
    }
    return NULL;
}

#endif  /* ndef MIME_INFO_H_ */
