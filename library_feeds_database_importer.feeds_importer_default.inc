<?php
/**
 * @file
 * library_feeds_database_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function library_feeds_database_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'library_database';
  $feeds_importer->config = array(
    'name' => 'Library Database',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'base_library_database',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Description',
            'target' => 'field_database_brief_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Link',
            'target' => 'field_database_link:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title',
            'target' => 'field_database_link:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Coverage Start',
            'target' => 'field_database_coverage:start',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => '1',
        'authorize' => 0,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['library_database'] = $feeds_importer;

  return $export;
}
