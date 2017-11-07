/* BEGIN LICENSE
 * Copyright (C) 2011-2013 Percona Ireland Ltd.
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 * END LICENSE */

#ifndef PERCONA_PLAYBACK_PLUGIN_LOAD_LIST_H
#define PERCONA_PLAYBACK_PLUGIN_LOAD_LIST_H

#define PANDORA_BUILTIN_LIST "audit_log,error_report,full_report,general_log,mysql_client,null_dbclient,query_log,simple_report,thread_per_connection,thread_pool"
#define PANDORA_BUILTIN_LOAD_LIST "audit_log,error_report,full_report,general_log,mysql_client,null_dbclient,query_log,simple_report,thread_per_connection,thread_pool"

/* List of plugins that should be loaded on startup if no
 * value is given for --plugin-load */
#define PANDORA_PLUGIN_LIST ""

/* The list of builtin plugins */
#define  PANDORA_BUILTIN_SYMBOLS_LIST _percona_playback_audit_log_plugin_,_percona_playback_error_report_plugin_,_percona_playback_full_report_plugin_,_percona_playback_general_log_plugin_,_percona_playback_mysql_client_plugin_,_percona_playback_null_dbclient_plugin_,_percona_playback_query_log_plugin_,_percona_playback_simple_report_plugin_,_percona_playback_thread_per_connection_plugin_,_percona_playback_thread_pool_plugin_
#define  PANDORA_BUILTIN_LOAD_SYMBOLS_LIST _percona_playback_audit_log_plugin_,_percona_playback_error_report_plugin_,_percona_playback_full_report_plugin_,_percona_playback_general_log_plugin_,_percona_playback_mysql_client_plugin_,_percona_playback_null_dbclient_plugin_,_percona_playback_query_log_plugin_,_percona_playback_simple_report_plugin_,_percona_playback_thread_per_connection_plugin_,_percona_playback_thread_pool_plugin_

#endif /* PERCONA_PLAYBACK_PLUGIN_LOAD_LIST_H */
