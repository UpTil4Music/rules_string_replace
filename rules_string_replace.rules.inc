<?php

/**
 * @file
 * A plugin for transforming data in rules.
 */

/**
 * Implements hook_rules_action_info().
 */
function rules_string_replace_rules_action_info() {
  $defaults = array(
    'group' => t('String Replace'),
    'parameter' => array(
      'subject' => array(
        'type' => 'text',
        'label' => t('Input text'),
      ),
    ),
    'provides' => array(
      'output_text' => array(
        'type' => 'text',
        'label' => t('Output text'),
      ),
    ),
  );
  return array(
    'string_replace' => array(
      'label' => t('String replace'),
      'base' => 'rules_string_replace_rules_action_replace',
      'parameter' => array(
        'subject' => array(
          'type' => 'text',
          'label' => t('String being searched, AKA the haystack'),
        ),
        'search' => array(
          'type' => 'text',
          'label' => t('Value being searched for, AKA the needle'),
        ),
		'replace' => array(
          'type' => 'text',
          'label' => t('The replacement value'),
          'optional' => TRUE,
          'default value' => '',
		  ),
      ),
    'provides' => array(
      'replaced_string' => array(
        'type' => 'text',
        'label' => t('Replaced string'),
      ),
    ),
    ) + $defaults,
  );
}

function rules_string_replace_rules_action_replace($subject, $search, $replace) {
  return array('replaced_string' => str_replace($search, $replace, $subject));
}
